    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "bitand.h"
    using namespace std;

    int main()
    {
        vector<int> vi;

        for (int idx = 0; idx < 10; ++idx)
            vi.push_back(idx);

        copy
        (
            vi.begin(),
            remove_if(vi.begin(), vi.end(), bind2nd(bit_and<int>(), 1)),
            ostream_iterator<int>(cout, " ")
        );
        cout << '\n';
    }
    /*
        Generated output:

        0 2 4 6 8
    */
