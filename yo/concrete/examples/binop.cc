#include <iostream>
using namespace std;

template <typename Class>
Class operator+(Class const &lhs, Class const &rhs)
{
    cout << "operator+(Class const &, Class const &)\n";

    Class tmp(lhs);
    return operator+(std::move(tmp), rhs);
}

template <typename Class>
Class operator+(Class &&lhs, Class const &rhs)
{
    cout << "operator+(Class &&lhs, Class const &rhs)\n";

    return lhs += rhs;
}

template <typename Class>
Class operator-(Class const &lhs, Class const &rhs)
{
    Class tmp(lhs);
    return operator-(std::move(tmp), rhs);
}

template <typename Class>
Class operator-(Class &&lhs, Class const &rhs)
{
    return lhs -= rhs;
}

class Class
{
    public:
        Class() = default;

        Class(int) {}

        Class(Class &&tmp)
        {
            cout << "Move constructor\n";
        }
        Class &operator+=(Class const &rhs)
        {
            cout << "operator+=\n";
        }
};

Class factory()
{
    return Class();
}

int main()
{
    Class lhs;
    Class rhs;

    Class result;
    result = lhs + rhs;
    result = factory() + rhs;
//  result = rhs + 2;       // this won't compile: the template functions 
                            // don't do promotions
//    result = lhs - rhs;   // this won't compile as operator-= hasn't been
                            // defined
}
    



