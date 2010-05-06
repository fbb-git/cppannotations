#include <iostream>
using namespace std;

    template<typename Fun, typename ArgType>
    void caller(Fun fun, ArgType &&arg)
    {
        fun(std::forward<ArgType>(arg));
    }

void display(ostream &out)
{
    out << "Hello fm display\n";
}

void increment(int &x)
{
    ++x;
}

int main()
{
    int x = 0;
    caller(display, cout);
    caller(increment, x);
    cout << "x is now: " << x << '\n';
}
