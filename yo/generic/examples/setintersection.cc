    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <iterator>
    using namespace std;

    bool caseless(string const &left, string const &right)
    {
        return strcasecmp(left.c_str(), right.c_str()) < 0;
    }
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
        cout << '\n';

        string set3[] = { "PAPA", "QUEBEC", "ROMEO"};

        copy(result,
            set_intersection(set1, set1 + 7, set3, set3 + 3, result, 
                                                             caseless),
            ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            papa quebec
            papa quebec
    */
