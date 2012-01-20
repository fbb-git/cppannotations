    #include <iostream>
    #include "add.h"

    size_t fun(int (*f)(int *p, size_t n));
    double fun(double (*f)(double *p, size_t n));

    int main()
    {
        std::cout << fun(add);
    }
