#include <iostream>

using namespace std;

class Binary
{
    public:
        Binary() = default;
        Binary(Binary const &other)
        {
            cout << "Copy constructor\n";
        }
        Binary(Binary &&tmp)
        {
            cout << "Move constructor\n";
        }
        Binary &operator+=(Binary const &rhs) &&
        {
            cout << "Move +=\n";
            return *this;
        }
        Binary &operator+=(Binary const &rhs) &
        {
            cout << "Copy +=\n";
            Binary tmp(*this);
            std::move(tmp) += rhs;
            swap(tmp);
            return *this;
        }
        void swap(Binary &rhs)
        {}
};

Binary &&operator+(Binary &&lhs, Binary const &rhs)
{
    cout << "move operator + called and returns\n";
    return move(move(lhs) += rhs);
}

Binary &&operator+(Binary const &lhs, Binary const &rhs)
{
    cout << "copy operator + called\n";
    Binary tmp(lhs);
    cout << "copy operator + returns\n";
    return move(tmp) + rhs;
}

int main()
{
    Binary d1;
    d1 + d1 + d1;
    cout << "========\n";
    Binary{} + Binary{} + Binary{};
}
