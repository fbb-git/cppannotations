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
        cout << '\n'
             << "Leftover elements are:\n";
        copy(removed, words + size, ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
                        Removing all "alpha"s:
                        kilo lima mike november papa quebec
                        Leftover elements are:
                        alpha alpha alpha papa quebec
    */
