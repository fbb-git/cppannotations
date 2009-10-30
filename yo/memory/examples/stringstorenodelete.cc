    #include <iostream>
    #include "stringstore.h"
    using namespace std;

    StringStore::~StringStore()
    {
        cout << "StringStore destructor called" << '\n';
    }

    int main()
    {
        StringStore **ptr = new StringStore* [2];

        ptr[0] = new StringStore[2];
        ptr[1] = new StringStore[2];

        delete[] ptr;
    }
