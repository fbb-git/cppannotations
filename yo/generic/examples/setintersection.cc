    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>

    class CaseLess
    {
        public:
            bool operator()(std::string const &left, std::string const &right)
            {
                return strcasecmp(left.c_str(), right.c_str()) < 0;
            }
    };

    using namespace std;

    int main()
    {
        string set1[] = { "kilo", "lima", "mike", "november",
                          "oscar", "papa", "quebec" };
        string set2[] = { "papa", "quebec", "romeo"};
        string result[7];
        string *returned;

        copy(result,
            set_intersection(set1, set1 + 7, set2, set2 + 3, result),
            ostream_iterator<string>(cout, " "));
        cout << endl;

        string set3[] = { "PAPA", "QUEBEC", "ROMEO"};

        copy(result,
            set_intersection(set1, set1 + 7, set3, set3 + 3, result,
            CaseLess()),
            ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        papa quebec
        papa quebec
    */
