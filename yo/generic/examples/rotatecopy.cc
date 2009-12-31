    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
            { "kilo", "lima", "mike", "november", "oscar", "papa",
              "echo", "foxtrot", "golf", "hotel", "india", "juliet" };
        size_t const size = sizeof(words) / sizeof(string);
        size_t midsize = 6;
        string out[size];

        copy(out,
            rotate_copy(words, words + midsize, words + size, out),
            ostream_iterator<string>(cout, " "));
        cout << '\n';

        return 0;
    }
    /*
        Displays:

        echo foxtrot golf hotel india juliet kilo lima mike november oscar papa
    */
