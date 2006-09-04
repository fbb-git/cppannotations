    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>

    class Twice
    {
        public:
            bool operator()(unsigned first, unsigned second) const
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
        (                                               // sequence starting
            find_first_of(sarr, last, search, search + 3),  // at 1st 'foxtrot'
            last, ostream_iterator<string>(cout, " ")
        );
        cout << endl;

        unsigned range[] = {2, 4, 6, 8, 10, 4, 6, 8, 10};
        unsigned nrs[]   = {2, 3, 4};

        copy            // sequence of values starting at first sequence
        (               // of range[] that are twice the values in nrs[]
            find_first_of(range, range + 9, nrs, nrs + 3, Twice()),
            range + 9, ostream_iterator<unsigned>(cout, " ")
        );
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        foxtrot golf hotel foxtrot golf hotel india juliet kilo
        4 6 8 10 4 6 8 10
    */
