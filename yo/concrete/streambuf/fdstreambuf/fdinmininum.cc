#include "inok/minimum.h"
#include <string>
#include <iostream>
#include <istream>

using namespace std;

int main(int argc)
{
    fdstreambuf
        fds(0, 12, 5, ios::in);
    istream
        is(&fds);
    string
        s;

    for (size_t line = 0; getline(is, s); line++)
    {
        cout <<  s << '\n';
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
