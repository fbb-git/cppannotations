#include <iostream>
#include "fistream.h"

using namespace std;
using namespace FBB;

//MAIN
    int main()
    {
        Fistream fis(cin);

        fis >> hex;
        while (true)
        {
            size_t x;
            switch (x = fis.get())
            {
                case '\n':
                    cout << endl;
                break;
                case '+':
                    cout << ' ';
                break;
                case '%':
                    fis >> field(2) >> x >> field(0);
                // FALLING THROUGH
                default:
                    cout << static_cast<char>(x);
                break;
                case EOF:
                return 0;
            }
        }
    }
    /*
        Generated output after:
            echo My+name+is+%60Ed%27 | a.out

        My name is `Ed'
    */
//=
