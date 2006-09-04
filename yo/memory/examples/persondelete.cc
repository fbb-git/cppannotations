    #include <iostream>
    #include "person.h"
    using namespace std;

    Person::~Person()
    {
        cout << "Person destructor called" << endl;
    }

    int main()
    {
        Person *a  = new Person[2];

        cout << "Destruction with []'s" << endl;
        delete[] a;

        a = new Person[2];

        cout << "Destruction without []'s" << endl;
        delete a;

        return 0;
    }
/*
    Generated output:
Destruction with []'s
Person destructor called
Person destructor called
Destruction without []'s
Person destructor called
*/
