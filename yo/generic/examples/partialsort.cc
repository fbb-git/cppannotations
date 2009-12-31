    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        int ia[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

        partial_sort(ia, ia + 3, ia + 10);

        cout << "find the 3 smallest elements:\n";
        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "find the 5 biggest elements:\n";
        partial_sort(ia, ia + 5, ia + 10, greater<int>());
        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            find the 3 smallest elements:
            1 2 3 7 9 5 4 6 8 10
            find the 5 biggest elements:
            10 9 8 7 6 1 2 3 4 5
    */
