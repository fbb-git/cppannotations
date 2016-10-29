    #include <iostream>
    #include "add.h"

    int fun(int (*f)(int const &lhs, int const &rhs));
    double fun(double (*f)(double const &lhs, double const &rhs));

    int main()
    {
        std::cout << fun(add<int>) << '\n';
    }
