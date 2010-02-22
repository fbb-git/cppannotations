    #include <iostream>
    #include <istream>
    #include <unistd.h>
    #include "ifdbuf.h"
    using namespace std;

    int main(int argc)
    {
        IFdStreambuf fds(STDIN_FILENO);
        istream      is(&fds);

        cout << is.rdbuf();
    }
