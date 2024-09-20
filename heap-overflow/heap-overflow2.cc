#include <string>
#include <iostream>
#include <cstring>

using namespace std;

struct data
{
    char name[64];
};

struct fp
{
    void (*fp)(string);
};

void win(string name)
{
    cout << "Hey, " << name << ". You win!" << endl;
    exit(0);
}

void normal(string name)
{
    cout << "Hello, " << name << ". This is a normal exit" << endl;
    exit(0);
}

void enter_name(struct data *, const char *);

int main(int argc, char **argv)
{
    string s;
    struct data *d;
    struct fp *f;

    cout << "Enter a string: ";
    cin >> s;

    d = (struct data *)malloc(sizeof(struct data));
    f = (struct fp *)malloc(sizeof(struct fp));

    // setup the function pointer
    f->fp = normal;

    // get the name of the user
    enter_name(d, s.c_str());

    // call the function
    f->fp(s);
}

void enter_name(struct data *d, const char *src)
{
    strcpy(d->name, src);
}