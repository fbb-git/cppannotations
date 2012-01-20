    #include <iostream>
    #include <istream>
    #include "ifdbuf.h"
    using namespace std;

//MAIN
    int main()
    {
        IFdStreambuf fds(STDIN_FILENO);
        istream      is(&fds);

        cout << is.rdbuf();
    }
//=
