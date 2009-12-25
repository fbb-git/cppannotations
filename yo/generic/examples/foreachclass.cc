    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <cctype>

    void lowerCase(char &c)
    {
        c = tolower(c);
    }

    class Show
    {
        int d_count;

        public:
            Show()
            :
                d_count(0)
            {}

            void operator()(std::string &str)
            {
                std::for_each(str.begin(), str.end(), lowerCase);
                str[0] = toupper(str[0]);   // here assuming str.length()
                std::cout << ++d_count << " " << str << "; ";
            }

            int count() const
            {
                return d_count;
            }
    };

    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "BRAVO", "charley", "DELTA", "echo",
                "FOXTROT", "golf", "HOTEL"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);

        cout << for_each(sarr, last, Show()).count() << endl;

        return 0;
    }
    /*
        Generated output (all on a single line):

        1 Alpha; 2 Bravo; 3 Charley; 4 Delta; 5 Echo; 6 Foxtrot;
                                                      7 Golf; 8 Hotel; 8
    */
