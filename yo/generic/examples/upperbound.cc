    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        int         ia[] = {10, 15, 15, 20, 30};
        size_t    n = sizeof(ia) / sizeof(int);

        cout << "Sequence: ";
        copy(ia, ia + n, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "15 can be inserted before " <<
                *upper_bound(ia, ia + n, 15) << '\n';
        cout << "35 can be inserted after " <<
                (upper_bound(ia, ia + n, 35) == ia + n ?
                                    "the last element" : "???") << '\n';

        sort(ia, ia + n, greater<int>());

        cout << "Sequence: ";
        copy(ia, ia + n, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "15 can be inserted before " <<
                *upper_bound(ia, ia + n, 15, greater<int>()) << '\n';
        cout << "35 can be inserted before " <<
                (upper_bound(ia, ia + n, 35, greater<int>()) == ia ?
                                    "the first element " : "???") << '\n';
    }
    /*
        Displays:
            Sequence: 10 15 15 20 30
            15 can be inserted before 20
            35 can be inserted after the last element
            Sequence: 30 20 15 15 10
            15 can be inserted before 10
            35 can be inserted before the first element
    */
