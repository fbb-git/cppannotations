    #include <iostream>
    #include "add.h"

    size_t fun(size_t (*f)(size_t *p, size_t n));
    double fun(double (*f)(double *p, size_t n));

    int main()
    {
        std::cout
            << fun(static_cast<double (*)(double *, size_t)>(add))
            << std::endl;

        return 0;
    }
