    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iostream>
    using namespace std;

    class CaseString
    {
        public:
            bool operator()(string const &first,
                            string const &second) const
            {
                return !strcasecmp(first.c_str(), second.c_str());
            }
    };
    int main()
    {
        string first[] =
            {
                "Alpha", "bravo", "Charley", "delta", "Echo",
                "foxtrot", "Golf", "hotel"
            };
        string second[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        string *last = first + sizeof(first) / sizeof(string);

        cout << "The elements of `first' and `second' are pairwise " <<
            (equal(first, last, second) ? "equal" : "not equal") <<
            '\n' <<
            "compared case-insensitively, they are " <<
            (
                equal(first, last, second, CaseString()) ?
                    "equal" : "not equal"
            ) << '\n';
    }
    /*
        Displays:
            The elements of `first' and `second' are pairwise not equal
            compared case-insensitively, they are equal
    */
