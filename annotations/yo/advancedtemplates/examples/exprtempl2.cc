#include <iostream>
#include <string>
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

size_t g_binExpr;

template<typename LHS, typename RHS, template <typename> class  Operation>
struct BinExpr
{
    string d_name;

    typedef typename BasicType<RHS>::ObjType ObjType;
    typedef typename ObjType::value_type value_type;

    LHS const &d_lhs;
    RHS const &d_rhs;

    BinExpr(LHS const &lhs, RHS const &rhs)
    :
        d_name("BinExpr" + to_string(g_binExpr++)),
        d_lhs(lhs),
        d_rhs(rhs)
    {
        cout << "creating " << d_name <<
                " holding " << lhs.d_name << " and " << rhs.d_name << '\n';
    }

    BinExpr(BinExpr const &other)
    :
        d_name(other.d_name + "_cc"),
        d_lhs(other.d_lhs),
        d_rhs(other.d_rhs)
    {
        cout << "BinExpr copy cons " << d_name << "\n";
    }

    BinExpr(BinExpr &&tmp)
    :
        d_name(tmp.d_name + "_mc"),
        d_lhs(std::move(tmp.d_lhs)),
        d_rhs(std::move(tmp.d_rhs))
    {
        cout << "BinExpr move cons " << d_name << "\n";
    }

    size_t size() const
    {
        return d_lhs.size();
    }

    value_type operator[](size_t ix) const
    {
        static Operation<value_type> operation;
        cout << "computing " << d_lhs.d_name << '[' <<  ix << "] + " <<
                    d_rhs.d_name << '[' << ix << "]\n";

        auto ret =  operation(d_lhs[ix], d_rhs[ix]);

        cout <<  "computed " << d_lhs.d_name << '[' <<  ix << "] + " <<
                    d_rhs.d_name << '[' << ix << "]\n";

        return ret;

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

struct V: public vector<int>
{
    string d_name;
    static size_t s_nr;

    V(string name, int value)
    :
        vector<int> {value},
        d_name(name)
    {
        cout << "creating V " << d_name << '\n';
    }

    V()
    :
        d_name("tmp" + to_string(s_nr++))
    {
        cout << "creating V " << d_name << '\n';
    }

    V(V const &other)
    :
        vector<int>(other),
        d_name(other.d_name + "_cc")
    {
        cout << "V copy cons " << d_name << "\n";
    }
    V(V &&tmp)
    :
        vector<int>(std::move(tmp)),
        d_name(tmp.d_name + "_mc")
    {
        cout << "V move cons " << d_name << "\n";
    }

    V &operator=(V const &other)
    {
        cout << "assign " << other.d_name << " to " << d_name << '\n';
        d_name = other.d_name;
        static_cast<vector<int>&>(*this) = other;
        return *this;
    }

    V &operator=(V &&tmp)
    {
        cout << "moving  " << tmp.d_name << " to " << d_name << '\n';
        d_name = std::move(tmp.d_name);
        static_cast<vector<int>&>(*this) = std::move(tmp);
        return *this;
    }
};

size_t V::s_nr;

int main()
{
    V one{"one", 1};
    V two{"two", 2};
    V three{"three", 3};
    V four{"four", 0};

    four = one + two + three + four;

    cout << four.d_name << ' ' << four.size() << " first value = " <<
                four[0] << '\n';
}
