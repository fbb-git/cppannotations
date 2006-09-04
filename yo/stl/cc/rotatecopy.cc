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
        unsigned const size = sizeof(words) / sizeof(string);
        unsigned midsize = 6;
        string out[size];

        copy(out,
            rotate_copy(words, words + midsize, words + size, out),
            ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        echo foxtrot golf hotel india juliet kilo lima mike november oscar papa
    */
