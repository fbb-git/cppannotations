#include <iostream>
#include <cstring>

using namespace std;

template <class T>
void mswap(T& a, T& b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

struct Data
{
    char *text;
    void copy(Data const &other)
    {
        cout << "A " << (void *)other.text << '\n';
        text = strdup(other.text);
        cout << "B " << (void *)text << '\n';
    }
    void copy(Data &&other)
    {
        cout << "D " << (void *)other.text << '\n';
        text = other.text;
        other.text = 0;
    }
};

Data makeData(char const *txt)
{
    Data ret;
    ret.text = strdup(txt);
    cout << "C " << (void *)ret.text << '\n';
    return ret;
}


class X
{
    public:
        X() { cout << "Constructor\n"; }
        X(X const &other) { cout << "Copycons\n"; }
        X(X &&other) { cout << "Move constructor\n"; }

        X &operator=(X const &other) { cout << "std op=\n"; return *this; };
        X &operator=(X &&other) { cout << "rref op=\n"; return *this; };

};


X &&fun()
{
    X x;
    return std::move(x);
}

int main()
{
    int &&i = int(3);
    ++i;
    cout << i << '\n';

    Data d1 = {strdup("hello")};
    Data d2;
    d2.copy(d1);
cout << "sep\n";
    Data d3;
    d3.copy(makeData("hello"));
cout << "sep 2\n";

    X &&xr = X();
    X x(fun());         // see memory/move.yo:
                        // No initialization of class objects by rvalues yet

cout << "sep 3\n";
    mswap(xr, x);
}
