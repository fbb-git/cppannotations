    #include <iostream>
    #include "stringstore.h"
    using namespace std;

    StringStore::~StringStore()
    {
        cout << "StringStore destructor called" << '\n';
    }

    int main()
    {
        StringStore *a  = new StringStore[2];

        cout << "Destruction with []'s" << '\n';
        delete[] a;

        a = new StringStore[2];

        cout << "Destruction without []'s" << '\n';
        delete a;
    }
/*
    Generated output:
Destruction with []'s
StringStore destructor called
StringStore destructor called
Destruction without []'s
StringStore destructor called
*/
