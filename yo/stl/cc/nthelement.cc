    #include <algorithm>
    #include <iostream>
    #include <iterator>
    #include <functional>
    using namespace std;

    int main()
    {
        int ia[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

        nth_element(ia, ia + 3, ia + 10);

        cout << "sorting with respect to " << ia[3] << endl;
        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << endl;

        nth_element(ia, ia + 5, ia + 10, greater<int>());

        cout << "sorting with respect to " << ia[5] << endl;
        copy(ia, ia + 10, ostream_iterator<int>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        sorting with respect to 4
        1 2 3 4 9 7 5 6 8 10
        sorting with respect to 5
        10 8 7 9 6 5 3 4 2 1
    */
