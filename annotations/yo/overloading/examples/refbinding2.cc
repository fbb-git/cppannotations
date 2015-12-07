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
        Demo &operator+=(Demo const &rhs) &&
        {
            cout << "Move +=\n";
            return *this;
        }
        Demo &operator+=(Demo const &rhs) &
        {
            cout << "Copy +=\n";
            Demo tmp(*this);
            std::move(tmp) += rhs;
            swap(tmp);
            return *this;
        }
        void swap(Demo &rhs)
        {}
};

    Demo &&operator+(Demo &&lhs, Demo const &rhs)
    {
        cout << "move operator+\n";
        lhs += rhs;
        cout << "move operator+ returns\n";
        return move(lhs);
    }

    Demo &&operator+(Demo const &lhs, Demo const &rhs)
    {
        cout << "copy operator+\n";
        Demo tmp(lhs);
        // tmp += rhs;
        cout << "copy operator+ returns\n";
        return move(tmp +=  rhs);

        return move(tmp);
    }

int main()
{
    Demo d1;
    d1 + d1 + d1;
    cout << "========\n";
    Demo{} + d1 + d1;

}






