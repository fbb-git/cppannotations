    #include <iostream>
    #include "sumvector.h"

    unsigned fun(unsigned (*f)(unsigned *p, unsigned n));
    double fun(double (*f)(double *p, unsigned n));

    int main(int argc, char **argv)
    {
        std::cout << fun(sumVector<double>) << std::endl;
    }
