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
        cout << "Word '" << min(string("first"), string("second")) <<
                                    "' is lexicographically first\n";

        cout << "Word '" << min(string("first"), string("SECOND")) <<
                                    "' is lexicographically first\n";

        cout << "Word '" << min(string("first"), string("SECOND"),
                            CaseString()) << "' is lexicographically first\n";

        return 0;
    }
    /*
        Generated output:

        Word 'first' is lexicographically first
        Word 'SECOND' is lexicographically first
        Word 'first' is lexicographically first
    */
