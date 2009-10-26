    #include <iostream>
    #include "person.h"                 // given earlier

    void printperson(Person const &p)
    {
        cout << "Name    : " << p.name()     << "\n"
                "Address : " << p.address()  << "\n"
                "Phone   : " << p.phone()    << "\n"
                "Weight  : " << p.weight()   << '\n';
    }

    int main()
    {
        Person p;

        p.setName("Linus Torvalds");
        p.setAddress("E-mail: Torvalds@cs.helsinki.fi");
        p.setPhone(" - not sure - ");
        p.setWeight(75);           // kg.

        printperson(p);
    }
/*
    Produced output:

Name    : Linus Torvalds
Address : E-mail: Torvalds@cs.helsinki.fi
Phone   :  - not sure -
Weight  : 75

*/
