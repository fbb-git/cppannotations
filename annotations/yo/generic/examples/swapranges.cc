    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string first[] = {"alpha", "bravo", "charley"};
        string second[] = {"echo", "foxtrot", "golf"};
        size_t const n = sizeof(first) / sizeof(string);

        cout << "Before:\n";
        copy(first, first + n, ostream_iterator<string>(cout, " "));
        cout << '\n';
        copy(second, second + n, ostream_iterator<string>(cout, " "));
        cout << '\n';

        swap_ranges(first, first + n, second);

        cout << "After:\n";
        copy(first, first + n, ostream_iterator<string>(cout, " "));
        cout << '\n';
        copy(second, second + n, ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            Before:
            alpha bravo charley
            echo foxtrot golf
            After:
            echo foxtrot golf
            alpha bravo charley
    */
