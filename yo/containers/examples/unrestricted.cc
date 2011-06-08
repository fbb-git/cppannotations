#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <cstring>
#include <complex>
#include <utility>
#include <algorithm>

using namespace std;

class Complex
{
    public:
        Complex(double, double)
        {
            cout << "Complex constructor\n";
        }
        Complex(Complex const &other)
        {
            cout << "Complex copy constructor\n";
        }
        ~Complex()
        {
            cout << "Complex destructor\n";
        }
        Complex &operator=(Complex const &other)
        {
            cout << "Complex operator=\n";
        }
};


class String
{
    friend ostream &operator<<(ostream &out, String const &str);

    string d_str;
    public:
        String(std::string const &txt)
        :
            d_str(txt)
        {
            cout << "String constructor\n";
        }
        String(String const &other)
        :
            d_str(other.d_str)
        {
            cout << "String copy constructor\n";
        }
        ~String()
        {
            cout << "String destructor\n";
        }
        String &operator=(String const &other)
        {
            d_str = other.d_str;
            cout << "String operator=\n";
        }
};

ostream &operator<<(ostream &out, String const &str)
{
    return out << str.d_str;
}

union Union
{
#if 0
    typedef complex<double>    Type1;
    typedef string             Type2;
#else
    typedef Complex            Type1;
    typedef String             Type2;
#endif

    pair<int, int> u_int;
    pair<int, Type1> u_complex;
    pair<int, Type2> u_string;

    Union(Union const &other);
    Union(int i);
    Union(double real, double imaginary);
    Union(string const &str);

    ~Union();

    int &asInt();
    Type1 &asComplex();
    Type2 &asString();

    Union &operator=(Union &&tmp);
    Union &operator=(Union const &rhs);

    void swap(Union &other);
};

int &Union::asInt()
{
    return u_int.second;
}

Union::Type1 &Union::asComplex()
{
    return u_complex.second;
}

Union::Type2 &Union::asString()
{
    return u_string.second;
}


Union::Union(Union const &other)
{
    switch (other.u_int.first)
    {
        case 1:
            new (&u_int) pair<int, int>(other.u_int);
        break;
        case 2:
            new (&u_complex) pair<int, Type1>(other.u_complex);
        break;
        case 3:
            new (&u_string) pair<int, Type2>(other.u_string);
        break;
    }
}

Union::Union(int i)
:
    u_int(1, i)
{}

Union::Union(double real, double imaginary)
:
    u_complex(2, {real, imaginary})
{}

Union::Union(string const &str)
:
    u_string(3, str)
{}

Union::~Union()
{
    switch (u_int.first)
    {
        case 2:
            u_complex.second.~Type1();
        break;

        case 3:
            u_string.second.~Type2();
        break;
    }
}

Union &Union::operator=(Union &&tmp)
{
    swap(tmp);
    return *this;
}

Union &Union::operator=(Union const &other)
{
    Union tmp(other);
    return *this = std::move(tmp);
}

void Union::swap(Union &other)
{
    char memory[sizeof(Union)];
    memcpy(memory, &other, sizeof(Union));
    memcpy(&other, this,   sizeof(Union));
    memcpy(this, memory,   sizeof(Union));
}


int main()
{
    Union ustr("hello world");
    Union ucom(12.4, 12.5);

    ustr = ucom;
    ustr = Union("hi there, again");
    cout << ustr.asString() << '\n';
}
