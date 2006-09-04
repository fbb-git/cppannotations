#include "fdstreambuf.h"
#include <string>
#include <iostream>
#include <istream>

using namespace std;

int main(int argc)
{
    fdstreambuf
        fds(0, 5, ios::in);
    istream
        is(&fds);
    string
        s;

    cout <<  "START\n";

    for (unsigned line = 0; getline(is, s); line++)
    {
        cout << s << endl;
        if ((line & 3) == 0)
        {
            is.unget();
            is.unget();
            is.unget();
            is.unget();
        }
        is.clear();
    }
}
