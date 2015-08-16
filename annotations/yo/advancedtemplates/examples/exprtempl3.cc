#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template<typename LHS, typename RHS, template<typename> class Operation>
struct BinExpr;

template<typename Type>
struct BasicType
{
    typedef Type ObjType;
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

        for (size_t ix = 0, end = size(); ix != end; ++ix)
            retVal[ix] = (*this)[ix];

        return retVal;
    }
};

template<typename LHS, typename RHS>
BinExpr<LHS, RHS, plus>  operator+(LHS const &lhs, RHS const &rhs)
{
    return BinExpr<LHS, RHS, plus>(lhs, rhs);
}

struct VI: public vector<int>
{
    static size_t const s_max = 10000;


VI()
    :
        vector<int>(s_max, 1)
    {}
};

int main(int argc, char **argv)
{
    VI a, b, c, d;

    for (size_t idx = 0, count = stoul(argv[1]); idx != count; ++idx)
        d = a + b + c + d + a + b + c + d;

    cout << d.front() << ", " << d.back() << '\n';
}
