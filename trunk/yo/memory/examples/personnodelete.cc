    #include <iostream>
    #include "person.h"
    using namespace std;

    Person::~Person()
    {
        cout << "Person destructor called" << endl;
    }

    int main()
    {
        Person **a = new Person* [2];

        a[0] = new Person[2];
        a[1] = new Person[2];

        delete[] a;

        return 0;
    }
