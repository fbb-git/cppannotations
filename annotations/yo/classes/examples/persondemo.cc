    #include <iostream>
    #include "person.h"                 // given earlier
    using namespace std;

    void printperson(Person const &p)
    {
        cout << "Name    : " << p.name()     << "\n"
                "Address : " << p.address()  << "\n"
                "Phone   : " << p.phone()    << "\n"
                "Mass  : " << p.mass()   << '\n';
    }

    int main()
    {
        Person p;

        p.setName("Linus Torvalds");
        p.setAddress("E-mail: Torvalds@cs.helsinki.fi");
        p.setPhone("");
        p.setMass(75);           // kg.

        printperson(p);
    }
/*
    Produced output:

Name    : Linus Torvalds
Address : E-mail: Torvalds@cs.helsinki.fi
Phone   :  - not available -
Mass  : 75

*/
