#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

    // BEFORE COMPILING THIS SOURCE: COMMENT OUT `outer(arg);' BELOW

//INT
    template <typename Type>
    void outer(Type t)
    {
        t.x();
    }
    void useInt()
    {
        int arg;
        outer(arg);
    }
//=


//DOUBLE
    void sqrtArg(double &arg)
    {
        arg = sqrt(arg);
    }
    template<typename Fun, typename Arg>
    void call(Fun fun, Arg arg)
    {
        fun(arg);
        cout << "In call: arg = " << arg << '\n';
    }
//=

//MAIN
    int main()
    {
        double value = 3;
        call(sqrtArg, value);
        cout << "Passed value, returns: " << value << '\n';

        call(sqrtArg, ref(value));
        cout << "Passed ref(value), returns: " << value << '\n';
    }
    /*
        Displays:
            In call: arg = 1.73205
            Passed value, returns: 3
            In call: arg = 1.73205
            Passed ref(value), returns: 1.73205
    */
//=
