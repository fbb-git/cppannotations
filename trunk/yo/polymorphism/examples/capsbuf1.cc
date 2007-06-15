    #include "capsbuf1.h"
    using namespace std;

    int main()
    {
        CapsBuf     cb;

        ostream     out(&cb);

        out << hex << "hello " << 32 << " worlds" << endl;

        return 0;
    }
    /*
        Generated output:

        Hello 20 Worlds
    */
