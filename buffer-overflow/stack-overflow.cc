#include <string>
#include <iostream>
#include <cstring>

using namespace std;

void my_function(const char *);

void win()
{
    cout << "You win!" << endl;
    exit(0);
}

int main(int argc, char **argv)
{
    string s;

    cout << "Enter a string: ";
    cin >> s;

    my_function(s.c_str());

    cout << "Exiting normally" << endl;
}

void my_function(const char *src)
{
    int var1 = 1;
    // int var2 = 2;
    // int var3 = 3;
    // int var4 = 4;
    char copy[4];
    strcpy(copy, src);
}