#include <iostream>

using namespace std;

class Demo
{
    public:
        Demo() = default;
        Demo(Demo const &other)
        {
            cout << "Copy constructor\n";
        }
        Demo(Demo &&tmp)
        {
            cout << "Move constructor\n";
        }
        Demo &operator+=(Demo const &rhs)
        {
            cout << "Copy +=\n";
            Demo tmp(*this);
            // add rhs to tmp
            // swap tmp
            cout << "copy += returns\n";
            return *this;
        }
};

Demo operator+(Demo &&lhs, Demo const &rhs)
{
    cout << "move operator+\n";
    lhs += rhs;
    cout << "move operator+ returns\n";
    return std::move(lhs);
}

Demo operator+(Demo const &lhs, Demo const &rhs)
{
    cout << "copy operator+\n";
    Demo tmp(lhs);
    tmp += rhs;
    cout << "copy operator+ returns\n";
    return tmp;
}

int main()
{
    Demo d1;
    d1 + d1 + d1;
    cout << "========\n";
    Demo{} + d1 + d1;
}
