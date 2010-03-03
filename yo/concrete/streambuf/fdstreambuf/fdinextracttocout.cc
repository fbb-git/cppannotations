#include "inok/buf.1.h"
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

    cerr <<  "START\n";

    char
        c;

    while (is >> c)
        cerr << "\t\tGOT " << c << '\n';

    cerr << "Using fds(0)\n";
}
