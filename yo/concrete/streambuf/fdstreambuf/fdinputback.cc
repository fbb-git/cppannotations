#include "inok/buf.1.h"
#include <string>
#include <iostream>
#include <istream>

using namespace std;

int main(int argc)
{
    fdstreambuf
        fds(0, ios::in);
    istream
        is(&fds);

    cout <<  "START\n";

    char
        c;

    is.get(c);

    cout << c << endl;

    is.unget();

    cout << is.rdbuf();
}
