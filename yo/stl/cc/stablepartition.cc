    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        int org[] = {1, 3, 5, 7, 9, 10, 2, 8, 6, 4};
        int ia[10];
        int *split;

        copy(org, org + 10, ia);
        split = partition(ia, ia + 10, bind2nd(less_equal<int>(), ia[9]));
        cout << "Last element <= 4 is ia[" << split - ia - 1 << "]\n";

        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << endl;

        copy(org, org + 10, ia);
        split = stable_partition(ia, ia + 10,
                                    bind2nd(less_equal<int>(), ia[9]));
        cout << "Last element <= 4 is ia[" << split - ia - 1 << "]\n";

        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        Last element <= 4 is ia[3]
        1 3 4 2 9 10 7 8 6 5
        Last element <= 4 is ia[3]
        1 3 2 4 5 7 9 10 8 6
    */
