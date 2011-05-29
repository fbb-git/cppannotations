    #include <iostream>
    #include "sumvector.h"

    size_t fun(size_t (*f)(size_t *p, size_t n));
    double fun(double (*f)(double *p, size_t n));

    int main(int argc, char **argv)
    {
        std::cout << fun(sumVector<double>) << '\n';
    }
