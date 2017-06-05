#include <iostream>

using namespace std;

struct Return
{
    int first;
    double second;
};

Return fun()
{
    return Return{1, 12.5};
}

Return &fun2()
{
    static Return ret{4, 5};
    return ret;
}

int main()
{
    auto r1 = fun();

    cout << r1.first;

    auto [one, two] = fun();

    auto &&[rone, rtwo] = fun();

    auto &[lone, ltwo] = fun2();
}
