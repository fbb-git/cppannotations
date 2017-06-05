    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>
    using namespace std;

    class Twice
    {
        public:
            bool operator()(size_t first, size_t second) const
            {
                return first == (second << 1);
            }
    };
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
        (                                                 // sequence starting
            find_first_of(sarr, last, search, search + 3),// at 1st 'foxtrot'
            last, ostream_iterator<string>{ cout, " " }
        );
        cout << '\n';

        size_t range[] = {2, 4, 6, 8, 10, 4, 6, 8, 10};
        size_t nrs[]   = {2, 3, 4};

            // copy the sequence of values in 'range', starting at the
            // first element in 'range' that is equal to twice one of the
            // values in 'nrs', and ending at the last element of 'range'
        copy
        (
            find_first_of(range, range + 9, nrs, nrs + 3, Twice{}),
            range + 9, ostream_iterator<size_t>{ cout, " " }
        );
        cout << '\n';
    }
    /*
        Displays:
            foxtrot golf hotel foxtrot golf hotel india juliet kilo
            4 6 8 10 4 6 8 10
    */
