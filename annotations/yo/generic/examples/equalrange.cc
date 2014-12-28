    #include <algorithm>
    #include <functional>
    #include <iterator>
    #include <iostream>
    using namespace std;

    int main()
    {
        int                 range[] = {1, 3, 5, 7, 7, 9, 9, 9};
        size_t const      size = sizeof(range) / sizeof(int);

        pair<int *, int *>  pi;

        pi = equal_range(range, range + size, 6);

        cout << "Lower bound for 6: " << *pi.first << '\n';
        cout << "Upper bound for 6: " << *pi.second << '\n';

        pi = equal_range(range, range + size, 7);

        cout << "Lower bound for 7: ";
        copy(pi.first, range + size, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "Upper bound for 7: ";
        copy(pi.second, range + size, ostream_iterator<int>(cout, " "));
        cout << '\n';

        sort(range, range + size, greater<int>());

        cout << "Sorted in descending order\n";

        copy(range, range + size, ostream_iterator<int>(cout, " "));
        cout << '\n';

        pi = equal_range(range, range + size, 7, greater<int>());

        cout << "Lower bound for 7: ";
        copy(pi.first, range + size, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "Upper bound for 7: ";
        copy(pi.second, range + size, ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            Lower bound for 6: 7
            Upper bound for 6: 7
            Lower bound for 7: 7 7 9 9 9
            Upper bound for 7: 9 9 9
            Sorted in descending order
            9 9 9 7 7 5 3 1
            Lower bound for 7: 7 7 5 3 1
            Upper bound for 7: 5 3 1
    */
