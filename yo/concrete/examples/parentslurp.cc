    #include "parentslurp.h"

    #include <string>
    #include <iostream>

//PARENT
    void ParentSlurp::parentProcess()
    {
        std::string     line;
        size_t    nr = 1;

        while (getline(std::cin, line))
            std::cout << nr++ << ": " << line << '\n';

        waitForChild();
    }
//=
//MAIN
    int main()
    {
        ParentSlurp().fork();
    }
    /*
        Generated Output (example only, actually obtained output may differ):

        1: a.out
        2: bitand.h
        3: bitfunctional
        4: bitnot.h
        5: daemon.cc
        6: fdinseek.cc
        7: fdinseek.h
        ...
    */
//=
