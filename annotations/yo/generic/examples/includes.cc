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
        string first1[] =
            {
                "alpha", "bravo", "charley", "delta",  "echo",
                "foxtrot", "golf", "hotel"
            };
        string first2[] =
            {
                "Alpha", "bravo", "Charley", "delta",  "Echo",
                "foxtrot", "Golf", "hotel"
            };
        string second[] =
            {
                "charley", "foxtrot", "hotel"
            };
        size_t n = sizeof(first1) / sizeof(string);

        cout << "The elements of `second' are " <<
            (includes(first1, first1 + n, second, second + 3) ? "" : "not")
            << " contained in the first sequence:\n"
               "second is a subset of first1\n";

        cout << "The elements of `first1' are " <<
            (includes(second, second + 3, first1, first1 + n) ? "" : "not")
            << " contained in the second sequence\n";

        cout << "The elements of `second' are " <<
            (includes(first2, first2 + n, second, second + 3) ? "" : "not")
            << " contained in the first2 sequence\n";

        cout << "Using case-insensitive comparison,\n"
            "the elements of `second' are "
            <<
            (includes(first2, first2 + n, second, second + 3, CaseString()) ?
                "" : "not")
            << " contained in the first2 sequence\n";
    }
    /*
        Displays:
            The elements of `second' are  contained in the first sequence:
            second is a subset of first1
            The elements of `first1' are not contained in the second sequence
            The elements of `second' are not contained in the first2 sequence
            Using case-insensitive comparison,
            the elements of `second' are  contained in the first2 sequence
    */
