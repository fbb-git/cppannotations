    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;

    class CaseString
    {
        public:
            bool operator()(string const &first, string const &second) const
            {
                return strcasecmp(second.c_str(), first.c_str()) > 0;
            }
    };
    int main()
    {
        cout << "Word '" << max(string("first"), string("second")) <<
                                    "' is lexicographically last\n";

        cout << "Word '" << max(string("first"), string("SECOND")) <<
                                    "' is lexicographically last\n";

        cout << "Word '" << max(string("first"), string("SECOND"),
                            CaseString()) << "' is lexicographically last\n";
    }
    /*
        Displays:
            Word 'second' is lexicographically last
            Word 'first' is lexicographically last
            Word 'SECOND' is lexicographically last
    */
