    #include <iostream>
    #include "person.h"                 // given earlier

    void printperson(Person const &p)
    {
        cout << "Name    : " << p.name()     << endl <<
                "Address : " << p.address()  << endl <<
                "Phone   : " << p.phone()    << endl <<
                "Weight  : " << p.weight()   << endl;
    }

    int main()
    {
        Person p;

        p.setName("Linus Torvalds");
        p.setAddress("E-mail: Torvalds@cs.helsinki.fi");
        p.setPhone(" - not sure - ");
        p.setWeight(75);           // kg.

        printperson(p);
        return 0;
    }
/*
    Produced output:

Name    : Linus Torvalds
Address : E-mail: Torvalds@cs.helsinki.fi
Phone   :  - not sure -
Weight  : 75

*/
