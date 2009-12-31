    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cstring>
    #include <iterator>
    using namespace std;

    bool casestring(string const &first, string const &second)
    {
        return strcasecmp(first.c_str(), second.c_str()) == 0;
    }
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

        removed = unique(words, words + size, casestring);
        copy(words, removed, ostream_iterator<string>(cout, " "));
        cout << '\n'
             << "Trailing elements are:\n";
        copy(removed, words + size, ostream_iterator<string>(cout, " "));
        cout << '\n';
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
