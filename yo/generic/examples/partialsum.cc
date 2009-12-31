    #include <numeric>
    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        int ia[] = {1, 2, 3, 4, 5};
        int ia2[5];

        copy(ia2,
            partial_sum(ia, ia + 5, ia2),
            ostream_iterator<int>(cout, " "));
        cout << '\n';

        copy(ia2,
            partial_sum(ia, ia + 5, ia2, multiplies<int>()),
            ostream_iterator<int>(cout, " "));
        cout << '\n';

        return 0;
    }
    /*
        Displays:

        1 3 6 10 15
        1 2 6 24 120
    */
