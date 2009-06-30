#include <iostream>
using namespace std;

template <typename ... Chars>
double _kmh(Chars ... chars);

double _kmh()
{
    return 0;
}

template<size_t n>
struct factor
{
    enum { value = 10 * factor<n - 1>::value };
};

template<>
struct factor<0>
{
    enum {value = 1};
};

template <typename ... Chars>
double _kmh(char c, Chars ...chars)
{
    return (c - '0') * factor<sizeof...(Chars)>::value + _kmh(chars ...);
}

int main()
{
    cout << _kmh('1', '2', '3') << endl;
}
