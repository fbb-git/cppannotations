#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct VI: public vector<int>
{
    static size_t const s_max = 10000;
    VI()
    :
        vector<int>(s_max, 1)
    {}

    VI &operator+=(VI const &rhs)
    {
        for (size_t idx = 0; idx != s_max; ++idx)
            (*this)[idx] += rhs[idx];

        return *this;
    }
};

VI operator+(VI const &lhs, VI const &rhs)
{
    VI tmp{ lhs };

    tmp += rhs;
    return tmp;
}

VI &&operator+(VI &&tmp, VI const &rhs)
{
    tmp += rhs;
    return std::move(tmp);
}

int main(int argc, char **argv)
{
    VI a, b, c, d;

    for (size_t idx = 0, count = stoul(argv[1]); idx != count; ++idx)
        d = a + b + c + d + a + b + c + d;

    cout << d.front() << ", " << d.back() << '\n';
}
