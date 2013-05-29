    #include <iostream>
    #include "vector.h"

    int main()
    {
        Vector<int>
            vi(10);

        cout << vi[5] << '\n';
        vi.push_back(12);
        cout << vi[10] << '\n';

        copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
