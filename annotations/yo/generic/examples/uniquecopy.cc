    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iterator>
    #include <cstring>
    using namespace std;

    bool casestring(string const &first, string const &second)
    {
        return strcasecmp(first.c_str(), second.c_str()) == 0;
    }
    int main()
    {
        string words[] = {"oscar", "Alpha", "alpha", "alpha",
                                                        "papa", "quebec" };
        size_t const size = sizeof(words) / sizeof(string);
        vector<string> remaining;

        unique_copy(words, words + size, back_inserter(remaining));

        copy(remaining.begin(), remaining.end(),
                ostream_iterator<string>(cout, " "));
        cout << '\n';

        vector<string> remaining2;

        unique_copy(words, words + size,
                                back_inserter(remaining2), casestring);

        copy(remaining2.begin(), remaining2.end(),
                ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            oscar Alpha alpha papa quebec
            oscar Alpha papa quebec
    */
