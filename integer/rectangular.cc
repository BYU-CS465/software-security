// A program that demonstrates an integer overflow vulnerability.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    uint16_t width, height, total;
    char c;

    cout << "Welcome to Rectangular!" << endl;

    // get width
    cout << "Enter a width" << endl;
    cin >> width;

    // get height
    cout << "Enter a height" << endl;
    cin >> height;

    // get character
    cout << "Enter a character" << endl;
    cin >> c;

    // allocate memory
    total = width * height;
    char *rect = (char *)malloc((total) * sizeof(char));
    cout << "allocated: " << total << endl;

    // store the character
    for (int i = 0; i < width * height; i++)
        rect[i] = c;

    // print out the rectangle
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << rect[i * height + j];
        }
        cout << endl;
    }
}
