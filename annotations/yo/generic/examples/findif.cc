    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iterator>
    #include <iostream>
    using namespace std;

    class CaseName
    {
        std::string  d_string;

        public:
            CaseName(char const *str): d_string(str)
            {}
            bool operator()(std::string const &element) const
            {
                return strcasecmp(element.c_str(), d_string.c_str()) == 0;
            }
    };
    int main()
    {
        string sarr[] =
            {
                "Alpha", "Bravo", "Charley", "Delta", "Echo"
            };
        string  *last = sarr + sizeof(sarr) / sizeof(string);

        copy
        (
            find_if(sarr, last, CaseName{ "charley" }),
            last, ostream_iterator<string>{ cout, " " }
        );
        cout << '\n';

        if (find_if(sarr, last, CaseName{ "india" }) == last)
        {
            cout << "`india' was not found in the range\n";
            copy(sarr, last, ostream_iterator<string>{ cout, " " });
            cout << '\n';
        }
    }
    /*
        Displays:
            Charley Delta Echo
            `india' was not found in the range
            Alpha Bravo Charley Delta Echo
    */
