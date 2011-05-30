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
    cout << "operator-(Class const &, Class const &)\n";
    Class tmp(lhs);
    return operator-(std::move(tmp), rhs);
}

template <typename Class>
Class operator-(Class &&lhs, Class const &rhs)
{
    cout << "operator-(Class &&lhs, Class const &rhs)\n";
    return lhs -= rhs;
}

class BinOp
{
    public:
        BinOp() = default;

        BinOp(BinOp &&tmp)
        {
            cout << "Move constructor\n";
        }
        BinOp &operator+=(BinOp const &rhs)
        {
            cout << "operator+=\n";
        }
};


int main()
{
    BinOp lhs;
    BinOp rhs;

    BinOp result;
    result = lhs + rhs;
//    result = lhs - rhs;   // this won't compile as operator-= hasn't been
                            // defined
}
    
