#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename LHS, typename RHS, template<typename> class Operation>
struct BinExpr;

template<typename RHS>
struct BasicType
{
    typedef RHS ObjType;
};

template<typename LHS, typename RHS, template<typename> class Operation>
struct BasicType<BinExpr<LHS, RHS, Operation>>
{
    typedef typename BinExpr<LHS, RHS, Operation>::ObjType ObjType;
};

template<typename LHS, typename RHS, template <typename> class  Operation>
struct BinExpr
{
    typedef typename BasicType<RHS>::ObjType ObjType;
    typedef typename ObjType::value_type value_type;

    LHS const &d_lhs;
    RHS const &d_rhs;

    BinExpr(LHS const &lhs, RHS const &rhs)
    :
        d_lhs(lhs),
        d_rhs(rhs)
    {}

    size_t size() const
    {
        return d_lhs.size();
    }

    value_type operator[](size_t ix) const
    {
        static Operation<value_type> operation;
        return operation(d_lhs[ix], d_rhs[ix]);
    }

    operator ObjType() const
    {
        ObjType retVal;
        for (size_t ix = 0; ix != d_lhs.size(); ++ix)
            retVal.push_back((*this)[ix]);
        return retVal;
    }
};

template<typename LHS, typename RHS>
BinExpr<LHS, RHS, plus>  operator+(LHS const &lhs, RHS const &rhs)
{
    return BinExpr<LHS, RHS, plus>(lhs, rhs);
}

int main()
{
    vector<int> one {1, 2, 3};
    vector<int> two {4, 5, 6};

    vector<int> three = one + two + (one + two);

    auto four = one + two + (one + two);

    auto z = "hello world";

    cout << z << '\n';

    cout << three[0] << ' ' << three[2] << '\n';
    cout << four[0] << ' ' << four[2] << '\n';
}
