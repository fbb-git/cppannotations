#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//regex s_inetAddr(R"(^\s+inet addr:(\S+))");

struct VI: public vector<int>
{
    int d_v = 1;

    VI()
    {
        cout << "VI default\n";
    }
    ~VI()
    {
    }
    VI(VI const &other)
    :
        vector<int>(other),
        d_v(other.d_v)
    {
        cout << "VI copycons\n";
    }
    VI(VI &&tmp)
    :
        vector<int>(std::move(tmp)),
        d_v(tmp.d_v)
    {
        cout << "VI move cons\n";
    }

    VI &operator=(VI const &other)
    {
        VI tmp{ other };
        swap(tmp);
        return *this;
    }

    void swap(VI &other)
    {
        std::swap(d_v, other.d_v);
        static_cast<vector<int> &>(*this).swap(other);
    }

    VI &operator+=(VI const &rhs)
    {
        d_v += rhs.d_v;
        return *this;
    }
    VI &operator+=(VI &&tmp)
    {
        d_v += tmp.d_v;
        return *this;
    }
};

VI operator+(VI const &lhs, VI const &rhs)
{
    VI tmp{ lhs };

    cout << "adding, returning new object\n";

    tmp += rhs;
    return tmp;
}

VI &&operator+(VI &&tmp, VI const &rhs)
{
    cout << "adding, returning available temporary object\n";
    tmp += rhs;
    return std::move(tmp);
}

int main()
{
    VI a, b, c, d;

    d = a + b + c + d + a + b + c + d;
}
