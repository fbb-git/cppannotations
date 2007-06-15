    #include <algorithm>
    #include <iostream>
    #include <string>

    class CaseString
    {
        public:
            bool operator()(std::string const &first,
                            std::string const &second) const
            {
                return strcasecmp(second.c_str(), first.c_str()) > 0;
            }
    };

    using namespace std;

    int main()
    {
        cout << "Word '" << max(string("first"), string("second")) <<
                                    "' is lexicographically last\n";

        cout << "Word '" << max(string("first"), string("SECOND")) <<
                                    "' is lexicographically last\n";

        cout << "Word '" << max(string("first"), string("SECOND"),
                            CaseString()) << "' is lexicographically last\n";

        return 0;
    }
    /*
        Generated output:

        Word 'second' is lexicographically last
        Word 'first' is lexicographically last
        Word 'SECOND' is lexicographically last
    */
