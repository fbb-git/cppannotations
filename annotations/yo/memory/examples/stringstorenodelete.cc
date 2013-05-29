    #include <iostream>
    #include "strings.h"
    using namespace std;

    Strings::~Strings()
    {
        cout << "Strings destructor called" << '\n';
    }

    int main()
    {
        Strings **ptr = new Strings* [2];

        ptr[0] = new Strings[2];
        ptr[1] = new Strings[2];

        delete[] ptr;
    }
