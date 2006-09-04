    #include "person.h"
    #include <iostream>

    void showPerson()
    {
        Person karel("Karel", "Marskramerstraat", "038 420 1971");
        Person *frank = new Person("Frank", "Oostumerweg", "050 403 2223");

        cout << karel.name()     << ", " <<
                karel.address()  << ", " <<
                karel.phone()    << endl <<
                frank->name()    << ", " <<
                frank->address() << ", " <<
                frank->phone()   << endl;

        delete frank;
    }
