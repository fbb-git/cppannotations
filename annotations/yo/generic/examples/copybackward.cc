    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <iterator>
    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);

        copy
        (
            copy_backward(sarr + 3, last, last - 3),
            last,
            ostream_iterator<string>(cout, " ")
        );
        cout << '\n';
    }
    // Displays:    golf hotel foxtrot golf hotel foxtrot golf hotel
