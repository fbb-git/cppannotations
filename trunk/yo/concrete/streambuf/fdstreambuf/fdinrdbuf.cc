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

    cout <<  "START\n";

    cout << &fds;//is.rdbuf();

    cout.clear();               // because of cerr.eof()

    cout << "Using fds(0)\n";
}
