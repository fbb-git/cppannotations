#include <iostream>
#include "a2x.h"

using namespace std;

// compile with a2xis.cc

int main()
{
//MAIN
    int x = A2x("12");          // initialize int x from a string "12"
    A2x a2x("12.50");           // explicitly create an A2x object

    double d;
    d = a2x;                    // assign a variable using an A2x object
    cout << d << '\n';

    a2x = "err";
    d = a2x;                    // d is 0: the conversion failed,
    cout << d << '\n';          // and a2x.good() == false

    a2x = " a";                 // reassign a2x to new text
    char c = a2x;               // c now 'a': internally operator>>() is used
    cout << c << '\n';          // so initial blanks are skipped.

    int expectsInt(int x);      // initialize a parameter using an
    expectsInt(A2x("1200"));    // anonymous A2x object

    d = A2x("12.45").to<int>(); // d is 12, not 12.45
    cout << d << '\n';
//=
}

int expectsInt(int x)
{
    cout << x << '\n';
    return x;
}
