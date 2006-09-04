    #include "capsbuf2.h"

    using namespace std;

    int main()
    {
        capsbuf
            cb;

        ostream
            out(&cb);

        cin >> out.rdbuf();
    }
