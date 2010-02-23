    #include "fdunget.h"
    #include <string>
    #include <iostream>
    #include <istream>
    using namespace std;

    int main()
    {
        FdUnget fds(0, 3, 2);
        istream is(&fds);
        char    c;

        for (int idx = 0; idx < 10; ++idx)
        {
            cout << "after reading " << idx << " characters:\n";
            for (int ug = 0; ug <= 6; ++ug)
            {
                if (!is.unget())
                {
                    cout
                    << "\tunget failed at attempt " << (ug + 1) << "\n"
                    << "\trereading: '";

                    is.clear();
                    while (ug--)
                    {
                        is.get(c);
                        cout << c;
                    }
                    cout << "'\n";
                    break;
                }
            }

            if (!is.get(c))
            {
                cout << " reached\n";
                break;
            }
            cout << "Next character: " << c << endl;
        }
    }
    /*
        Generated output after 'echo abcde | program':

        after reading 0 characters:
                unget failed at attempt 1
                rereading: ''
        Next character: a
        after reading 1 characters:
                unget failed at attempt 2
                rereading: 'a'
        Next character: b
        after reading 2 characters:
                unget failed at attempt 3
                rereading: 'ab'
        Next character: c
        after reading 3 characters:
                unget failed at attempt 4
                rereading: 'abc'
        Next character: d
        after reading 4 characters:
                unget failed at attempt 4
                rereading: 'bcd'
        Next character: e
        after reading 5 characters:
                unget failed at attempt 4
                rereading: 'cde'
        Next character:

        after reading 6 characters:
                unget failed at attempt 4
                rereading: 'de
        '
         reached
    */
