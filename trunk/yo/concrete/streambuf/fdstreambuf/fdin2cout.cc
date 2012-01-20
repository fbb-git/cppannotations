#include "fdstreambuf.h"
#include <string>
#include <iostream>
#include <istream>

using namespace std;

//    Calls uflow() repeatedly

int main(int argc)
{
    fdstreambuf
        fds(0, ios::in);
    istream
        is(&fds);

    cout << "START\n";

    char
        c;

    while (is.get(c))
        cout << "GOT " << c << '\n';

    cout << "Using fds(0)\n";
}
