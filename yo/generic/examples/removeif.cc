    #include <functional>
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

        cout << "Removing all \"alpha\"s:\n";

        string *removed = remove_if(words, words + size,
                    bind2nd(equal_to<string>(), string("alpha")));

        copy(words, removed, ostream_iterator<string>(cout, " "));
        cout << endl
             << "Trailing elements are:\n";
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
