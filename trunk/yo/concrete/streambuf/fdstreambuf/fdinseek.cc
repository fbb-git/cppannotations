#include "fdstreambuf.h"
#include <string>
#include <iostream>
#include <istream>
#include <iomanip.h>

using namespace std;

int main(int argc)
{
    fdstreambuf
        fds(0, ios::in);
    istream
        is(&fds);
    string
        s;

    cout <<  "START\n";

    while (true)
    {
        if (!getline(is, s))
            break;

        streampos
            pos = is.tellg();

        cout << setw(5) << pos << ": `" << s << "'\n";

        if (!getline(is, s))
            break;

        streampos
            pos2 = is.tellg();

        cout << setw(5) << pos2 << ": `" << s << "'\n";

        if (!is.seekg(pos))
        {
            cout << "Seek failed\n";
            return 1;
        }
    }
}
