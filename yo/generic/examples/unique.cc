    #include <algorithm>
    #include <iostream>
    #include <string>
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
        string words[] = {"alpha", "alpha", "Alpha", "papa", "quebec" };
        size_t const size = sizeof(words) / sizeof(string);

        string *removed = unique(words, words + size);
        copy(words, removed, ostream_iterator<string>(cout, " "));
        cout << '\n'
             << "Trailing elements are:\n";
        copy(removed, words + size, ostream_iterator<string>(cout, " "));
        cout << '\n';

        removed = unique(words, words + size, CaseString());
        copy(words, removed, ostream_iterator<string>(cout, " "));
        cout << '\n'
             << "Trailing elements are:\n";
        copy(removed, words + size, ostream_iterator<string>(cout, " "));
        cout << '\n';

        return 0;
    }
    /*
        Displays:

        alpha Alpha papa quebec
        Trailing elements are:
        quebec
        alpha papa quebec
        Trailing elements are:
        quebec quebec
    */
