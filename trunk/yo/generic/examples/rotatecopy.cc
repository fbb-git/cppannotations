    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
           { "kilo", "lima", "mike", "november", "oscar",
              "foxtrot", "golf", "hotel", "india", "juliet" };
        size_t const size = sizeof(words) / sizeof(string);
        size_t const midsize = size / 2;
        string out[size];

        copy(out,
            rotate_copy(words, words + midsize, words + size, out),
            ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            foxtrot golf hotel india juliet kilo lima mike november oscar
    */
