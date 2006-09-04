    #include <iostream>
    #include "person.h"

    Person::~Person()
    {
        cout << "Person destructor called" << endl;
    }

    int main()
    {
        Person **a = new Person* [2];

        a[0] = new Person[2];
        a[1] = new Person[2];

        for (int index = 0; index < 2; index++)
            delete[] a[index];

        delete[] a;
    }
    /*
        Generated output:
Person destructor called
Person destructor called
Person destructor called
Person destructor called
    */
