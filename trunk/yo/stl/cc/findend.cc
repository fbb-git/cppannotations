    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>

    class Twice
    {
        public:
            bool operator()(size_t first, size_t second) const
            {
                return first == (second << 1);
            }
    };

    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel",
                "foxtrot", "golf", "hotel",
                "india", "juliet", "kilo"
            };
        string search[] =
            {
                "foxtrot",
                "golf",
                "hotel"
            };
        string  *last = sarr + sizeof(sarr) / sizeof(string);

        copy
        (
            find_end(sarr, last, search, search + 3),   // sequence starting
            last, ostream_iterator<string>(cout, " ")   // at 2nd 'foxtrot'
        );
        cout << endl;

        size_t range[] = {2, 4, 6, 8, 10, 4, 6, 8, 10};
        size_t nrs[]   = {2, 3, 4};

        copy                // sequence of values starting at last sequence
        (                   // of range[] that are twice the values in nrs[]
            find_end(range, range + 9, nrs, nrs + 3, Twice()),
            range + 9, ostream_iterator<size_t>(cout, " ")
        );
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        foxtrot golf hotel india juliet kilo
        4 6 8 10
    */
