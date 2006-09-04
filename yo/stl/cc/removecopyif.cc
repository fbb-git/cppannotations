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
                "oscar", "alpha", "alpha", "papa", "quebec" };
        unsigned const size = sizeof(words) / sizeof(string);
        string remaining[
                            size -
                            count_if
                            (
                                words, words + size,
                                bind2nd(equal_to<string>(), "alpha")
                            )
                        ];
        string *returnvalue =
                    remove_copy_if
                    (
                        words, words + size, remaining,
                        bind2nd(equal_to<string>(), "alpha")
                    );

        cout << "Removing all \"alpha\"s:\n";
        copy(remaining, returnvalue, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        Removing all "alpha"s:
        kilo lima mike november oscar papa quebec
    */
