    #include <algorithm>
    #include <iostream>
    #include <iterator>
    #include <functional>
    using namespace std;

    int main()
    {
        int     ia[] = {10, 20, 30};

        cout << "Sequence: ";
        copy(ia, ia + 3, ostream_iterator<int>(cout, " "));
        cout << endl;

        cout << "15 can be inserted before " <<
                *lower_bound(ia, ia + 3, 15) << endl;
        cout << "35 can be inserted after " <<
                (lower_bound(ia, ia + 3, 35) == ia + 3 ?
                                    "the last element" : "???") << endl;

        iter_swap(ia, ia + 2);

        cout << "Sequence: ";
        copy(ia, ia + 3, ostream_iterator<int>(cout, " "));
        cout << endl;

        cout << "15 can be inserted before " <<
                *lower_bound(ia, ia + 3, 15, greater<int>()) << endl;
        cout << "35 can be inserted before " <<
                (lower_bound(ia, ia + 3, 35, greater<int>()) == ia ?
                                    "the first element " : "???") << endl;

        return 0;
    }
    /*
        Generated output:

        Sequence: 10 20 30
        15 can be inserted before 20
        35 can be inserted after the last element
        Sequence: 30 20 10
        15 can be inserted before 10
        35 can be inserted before the first element
    */
