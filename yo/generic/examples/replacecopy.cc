    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
            { "kilo", "alpha", "lima", "mike", "alpha", "november", "alpha",
                "oscar", "alpha", "alpha", "papa", "quebec" };
        size_t const size = sizeof(words) / sizeof(string);
        string remaining[size];

        copy
        (
            remaining,
            replace_copy(words, words + size, remaining, string("alpha"),
                                                         string("ALPHA")),
            ostream_iterator<string>(cout, " ")
        );
        cout << '\n';

        return 0;
    }
    /*
        Displays:

        kilo ALPHA lima mike ALPHA november ALPHA oscar ALPHA ALPHA papa quebec
    */
