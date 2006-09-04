    #include <iostream>
    #include "add.h"

    unsigned fun(int (*f)(int *p, unsigned n));
    double fun(double (*f)(double *p, unsigned n));

    int main()
    {
        std::cout << fun(add) << std::endl;
    }
