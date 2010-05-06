    #include <iostream>
    #include "sumvector.h"

    using namespace std;

    int main()
    {
        int     x[] = {1, 2};
        double  y[] = {1.1, 2.2};

        cout << sumVector(x, 2) << '\n'
            << sumVector(y, 2) << '\n';

        return 0;
    }
