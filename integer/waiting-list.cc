// A program that demonstrates an integer underflow vulnerability.

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
    int16_t inventory;     // amount on hand
    pthread_mutex_t mutex; // a mutex to provide atomic operations
};

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
    p.inventory = 1000;
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
    struct product *p;

    // recover the argument to the thread
    p = (struct product *)vptr;

    // Each thread represents a customer.
    // The customer either is able to buy the book or goes on the waiting list

    pthread_mutex_lock(&p->mutex);
    // always subtract one from the inventory
    p->inventory -= 1;
    // check if there is still sufficient inventory left
    if (p->inventory >= 0)
    {
        cout << pthread_self() << " purchased " << p->name << " and there are " << p->inventory << " left" << endl;
    }
    else
    {
        // 0 - inventory represents this customer's position on the waiting list
        cout << pthread_self() << " is at position " << 0 - p->inventory << " on the waiting list" << endl;
    }
    // release the lock
    pthread_mutex_unlock(&p->mutex);

    pthread_exit(&retval);
}