    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>

    class CaseString
    {
        public:
            bool operator()(std::string const &first,
                            std::string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) < 0;
            }
    };

    using namespace std;

    int main()
    {
        string range[] =
            {
                "alpha", "charley", "echo", "golf",
                "bravo", "delta", "foxtrot",
            };

        inplace_merge(range, range + 4, range + 7);
        copy(range, range + 7, ostream_iterator<string>(cout, " "));
        cout << endl;

        string range2[] =
            {
                "ALFA", "CHARLEY", "DELTA", "foxtrot", "hotel",
                "bravo", "ECHO", "GOLF"
            };

        inplace_merge(range2, range2 + 5, range2 + 8, CaseString());
        copy(range2, range2 + 8, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        alpha bravo charley delta echo foxtrot golf
        ALFA bravo CHARLEY DELTA ECHO foxtrot GOLF hotel
    */
