    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
            { "kilo", "alpha", "lima", "mike", "alpha", "november",
              "alpha", "oscar", "alpha", "alpha", "papa", "quebec" };
        size_t const size = sizeof(words) / sizeof(string);
        string result[size];

        replace_copy_if(words, words + size, result,
                        bind1st(greater<string>(), string("mike")),
                        string("ALPHA"));
        copy (result, result + size, ostream_iterator<string>(cout, " "));
        cout << '\n';

        return 0;
    }
    /*
        Displays (all on one line):

        ALPHA ALPHA ALPHA mike ALPHA november ALPHA oscar ALPHA ALPHA
                                                          papa quebec
    */
