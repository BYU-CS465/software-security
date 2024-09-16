// A program that fixes a TOCTOU (time of check, time of use) vulnerability using a mutex

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <vector>

using namespace std;

int retval = 1;

struct product
{
    string name;           // name of item
    int inventory;         // amount on hand
    pthread_mutex_t mutex; // a mutex to provide atomic operations
};

int check_and_decrement(struct product *p)
{
    pthread_mutex_lock(&p->mutex);
    // check if there is still sufficient inventory left
    if (p->inventory > 0)
    {
        p->inventory -= 1;
        pthread_mutex_unlock(&p->mutex);
        return 1;
    }
    else
    {
        pthread_mutex_unlock(&p->mutex);
        return 0;
    }
}

void *doit(void *);

void create_customers(int);

int main(int argc, char **argv)
{
    // first argument should be number of customers
    if (argc != 2)
    {
        printf("Usage: inventory [number of customers]\n");
        exit(-1);
    }
    int number_of_customers = atoi(argv[1]);

    // create customer threads
    create_customers(number_of_customers);
}

void create_customers(int number)
{
    // inventory of the product in shared memory
    struct product p;
    p.name = string("Intro to Computer Security");
    p.inventory = 10;
    pthread_mutex_init(&p.mutex, NULL);

    // initialize random number generator
    srandom(1000);

    vector<pthread_t> threads;
    cout << "Creating customers ... " << endl;
    for (int i = 0; i < number; i++)
    {
        pthread_t thread;
        pthread_create(&thread, NULL, &doit, &p);
        threads.push_back(move(thread));
    }

    for (int i = 0; i < number; i++)
    {
        pthread_join(threads[i], NULL);
    }

    cout << "Done" << endl;
}

void *
doit(void *vptr)
{
    long r;
    struct product *p;

    // recover the argument to the thread
    p = (struct product *)vptr;

    // Each thread represents a customer.
    // The customer looks up the product (including inventory amount),
    // waits a bit (they read the page, add the product to their cart, etc),
    // then makes a purchase, which decrements the inventory amount
    // We use sleep to represent the waiting.
    int amount = p->inventory;
    cout << pthread_self() << " would like buy " << p->name << " and there are " << amount << " left" << endl;
    r = random() % 100;
    usleep(r);
    // obtain the lock
    if (check_and_decrement(p))
    {
        cout << pthread_self() << " purchased " << p->name << " and there are " << p->inventory << " left" << endl;
    }
    else
    {
        cout << pthread_self() << " unable to purchase because there are none left." << endl;
    }
    pthread_exit(&retval);
}