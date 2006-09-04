    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string first[] = {"alpha", "bravo", "charley"};
        string second[] = {"echo", "foxtrot", "golf"};
        unsigned const n = sizeof(first) / sizeof(string);

        cout << "Before:\n";
        copy(first, first + n, ostream_iterator<string>(cout, " "));
        cout << endl;
        copy(second, second + n, ostream_iterator<string>(cout, " "));
        cout << endl;

        swap_ranges(first, first + n, second);

        cout << "After:\n";
        copy(first, first + n, ostream_iterator<string>(cout, " "));
        cout << endl;
        copy(second, second + n, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        Before:
        alpha bravo charley
        echo foxtrot golf
        After:
        echo foxtrot golf
        alpha bravo charley
    */
