    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
            { "kilo", "alpha", "lima", "mike", "alpha", "november", "alpha",
                "alpha", "alpha", "papa", "quebec" };
        string *removed;
        size_t const size = sizeof(words) / sizeof(string);

        cout << "Removing all \"alpha\"s:\n";
        removed = remove(words, words + size, "alpha");
        copy(words, removed, ostream_iterator<string>(cout, " "));
        cout << endl
             << "Leftover elements are:\n";
        copy(removed, words + size, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        Removing all "alpha"s:
        kilo lima mike november oscar papa quebec
        Trailing elements are:
        oscar alpha alpha papa quebec
    */
