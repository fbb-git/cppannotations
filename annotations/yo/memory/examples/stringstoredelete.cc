    #include <iostream>
    #include "strings.h"
    using namespace std;

    Strings::~Strings()
    {
        cout << "Strings destructor called" << '\n';
    }

    int main()
    {
        Strings *a  = new Strings[2];

        cout << "Destruction with []'s" << '\n';
        delete[] a;

        a = new Strings[2];

        cout << "Destruction without []'s" << '\n';
        delete a;
    }
/*
    Generated output:
Destruction with []'s
Strings destructor called
Strings destructor called
Destruction without []'s
Strings destructor called
*/
