    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
            { "kilo", "alpha", "lima", "mike", "alpha", "november", "alpha",
                "oscar", "alpha", "alpha", "papa"};
        size_t const size = sizeof(words) / sizeof(string);

        replace_if(words, words + size,
                   bind1st(equal_to<string>(), string("alpha")),
                   string("ALPHA"));
        copy(words, words + size, ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            kilo ALPHA lima mike ALPHA november ALPHA oscar ALPHA ALPHA papa
    */
