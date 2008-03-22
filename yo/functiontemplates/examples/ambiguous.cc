    #include <iostream>
    #include "add.h"

    int fun(int (*f)(int const &lvalue, int const &rvalue));
    double fun(double (*f)(double const &lvalue, double const &rvalue));

    int main()
    {
        std::cout << fun(add) << std::endl;
        return 0;
    }
