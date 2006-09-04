    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iterator>

    class CaseString
    {
        public:
            bool operator()(std::string const &first,
                            std::string const &second) const
            {
                return !strcasecmp(first.c_str(), second.c_str());
            }
    };

    using namespace std;

    int main()
    {
        string words[] = {"oscar", "Alpha", "alpha", "alpha",
                                                        "papa", "quebec" };
        unsigned const size = sizeof(words) / sizeof(string);
        vector<string> remaining;

        unique_copy(words, words + size, back_inserter(remaining));

        copy(remaining.begin(), remaining.end(),
                ostream_iterator<string>(cout, " "));
        cout << endl;

        vector<string> remaining2;

        unique_copy(words, words + size,
                                back_inserter(remaining2), CaseString());

        copy(remaining2.begin(), remaining2.end(),
                ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        oscar Alpha alpha papa quebec
        oscar Alpha papa quebec
    */
