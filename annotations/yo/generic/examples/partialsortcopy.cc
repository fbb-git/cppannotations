    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        int ia[] = {1, 10, 3, 8, 5, 6, 7, 4, 9, 2};
        int ia2[6];

        partial_sort_copy(ia, ia + 10, ia2, ia2 + 6);

        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << '\n';
        cout << "the 6 smallest elements: ";
        copy(ia2, ia2 + 6, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "the 4 smallest elements to a larger range:\n";
        partial_sort_copy(ia, ia + 4, ia2, ia2 + 6);
        copy(ia2, ia2 + 6, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "the 4 biggest elements to a larger range:\n";
        partial_sort_copy(ia, ia + 4, ia2, ia2 + 6, greater<int>());
        copy(ia2, ia2 + 6, ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            1 10 3 8 5 6 7 4 9 2
            the 6 smallest elements: 1 2 3 4 5 6
            the 4 smallest elements to a larger range:
            1 3 8 10 5 6
            the 4 biggest elements to a larger range:
            10 8 3 1 5 6
    */
