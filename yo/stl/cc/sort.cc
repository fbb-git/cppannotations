    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] = {"november", "kilo", "mike", "lima",
                          "oscar", "quebec", "papa"};

        sort(words, words + 7);
        copy(words, words + 7, ostream_iterator<string>(cout, " "));
        cout << endl;

        sort(words, words + 7, greater<string>());
        copy(words, words + 7, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        kilo lima mike november oscar papa quebec
        quebec papa oscar november mike lima kilo
    */
