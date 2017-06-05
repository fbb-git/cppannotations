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
        cout << "Word '" << min(string{ "first" }, string{ "second" }) <<
                                    "' is lexicographically first\n";

        cout << "Word '" << min(string{ "first" }, string{ "SECOND" }) <<
                                    "' is lexicographically first\n";

        cout << "Word '" << min(string{ "first" }, string{ "SECOND" },
                            CaseString{}) << "' is lexicographically first\n";
    }
    /*
        Displays:
            Word 'first' is lexicographically first
            Word 'SECOND' is lexicographically first
            Word 'first' is lexicographically first
    */
