    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>
    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo"
            };
        string  *last = sarr + sizeof(sarr) / sizeof(string);

        copy
        (
            find(sarr, last, "delta"), last, 
                                       ostream_iterator<string>(cout, " ")
        );
        cout << '\n';

        if (find(sarr, last, "india") == last)
        {
            cout << "`india' was not found in the range\n";
            copy(sarr, last, ostream_iterator<string>(cout, " "));
            cout << '\n';
        }
    }
    /*
        Displays:
            delta echo
            `india' was not found in the range
            alpha bravo charley delta echo
    */
