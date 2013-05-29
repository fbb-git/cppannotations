    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iterator>
    #include <iostream>
    using namespace std;

    class CaseString
    {
        public:
            bool operator()(string const &first, string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) < 0;
            }
    };
    int main()
    {
        string range[] =
            {
                "alpha", "charley", "echo", "golf",
                "bravo", "delta", "foxtrot",
            };

        inplace_merge(range, range + 4, range + 7);
        copy(range, range + 7, ostream_iterator<string>(cout, " "));
        cout << '\n';

        string range2[] =
            {
                "ALFA", "CHARLEY", "DELTA", "foxtrot", "hotel",
                "bravo", "ECHO", "GOLF"
            };

        inplace_merge(range2, range2 + 5, range2 + 8, CaseString());
        copy(range2, range2 + 8, ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            alpha bravo charley delta echo foxtrot golf
            ALFA bravo CHARLEY DELTA ECHO foxtrot GOLF hotel
    */
