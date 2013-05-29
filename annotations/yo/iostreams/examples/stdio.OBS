#include <stdiostream.h>

int main()
{
    stdiobuf
        f = fopen("stdio.cc", "r");         // open this source to read

    cout << &f;                             // copy it to cout

    fprintf(cout.rdbuf(), "hello world\n"); // append `hello world', using
                                            // a C function.
    return 0;

/*
    output produced:

    the contents of this file, and an extra line
    containing the text `hello world'
*/
}
