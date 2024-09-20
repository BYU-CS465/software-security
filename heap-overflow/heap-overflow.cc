#include <string>
#include <iostream>
#include <cstring>

using namespace std;

struct data
{
    char name[64];
    int role;
};

void enter_name(struct data *, const char *);

int main(int argc, char **argv)
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    struct data *d;
    d = (struct data *)malloc(sizeof(struct data));

    enter_name(d, s.c_str());

    cout << "Role is " << d->role << endl;
    if (d->role == 0)
    {
        cout << "Hello, " << d->name << ", you have been granted admin status." << endl;
    }
    else
    {
        cout << "Hello, " << d->name << ", you are an ordinary user." << endl;
    }
}

void enter_name(struct data *d, const char *src)
{
    // use 1 for ordinary users, 0 for admin
    d->role = 1;
    strcpy(d->name, src);
}