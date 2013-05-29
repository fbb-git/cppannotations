#include <string>
#include <iostream>

using namespace std;

class X
{
    public:

    void fun() { cout << "hello\n"; }

    void (X::*fp)();

    string
        X::*sp,
        str;

};

int main()
{
    X x;

    x.fp = &X::fun;

    (x.*(x.fp))();

    x.sp = &X::str;
    x.*(x.sp) = "hello world";

    cout << x.str;
}
