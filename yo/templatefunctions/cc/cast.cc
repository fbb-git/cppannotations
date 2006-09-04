    #include <iostream>
    #include "add.h"

    unsigned fun(unsigned (*f)(unsigned *p, unsigned n));
    double fun(double (*f)(double *p, unsigned n));

    int main()
    {
        std::cout
            << fun(static_cast<double (*)(double *, unsigned)>(add))
            << std::endl;

        return 0;
    }
