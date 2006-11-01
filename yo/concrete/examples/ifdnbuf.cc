    #include <unistd.h>
    #include <iostream>
    #include <istream>
    #include "ifdnbuf.h"
    using namespace std;

    int main(int argc)
    {
                                    // internally: 30 char buffer
        ifdnstreambuf fds(STDIN_FILENO, 30);

        char buf[80];               // main() reads blocks of 80
                                    // chars
        while (true)
        {
            size_t n = fds.sgetn(buf, 80);
            if (n == 0)
                break;
            cout.write(buf, n);
        }
    }
