    #include <functional>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cctype>
    #include <iterator>

    class Caps
    {
        public:
            std::string operator()(std::string const &src)
            {
                std::string tmp = src;

                transform(tmp.begin(), tmp.end(), tmp.begin(), toupper);
                return tmp;
            }
    };

    using namespace std;

    int main()
    {
        string words[] = {"alpha", "bravo", "charley"};

        copy(words, transform(words, words + 3, words, Caps()),
                                ostream_iterator<string>(cout, " "));
        cout << endl;

        int         values[] = {1, 2, 3, 4, 5};
        vector<int> squares;

        transform(values, values + 5, values,
                                back_inserter(squares), multiplies<int>());

        copy(squares.begin(), squares.end(),
                                ostream_iterator<int>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        ALPHA BRAVO CHARLEY
        1 4 9 16 25
    */
