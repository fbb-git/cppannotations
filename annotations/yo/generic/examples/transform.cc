    #include <functional>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cctype>
    #include <iterator>
    using namespace std;

    string caps(string const &src)
    {
        string tmp;
        tmp.resize(src.length());

        transform(src.begin(), src.end(), tmp.begin(), ::toupper);
        return tmp;
    }
    int main()
    {
        string words[] = {"alpha", "bravo", "charley"};

        copy(words, transform(words, words + 3, words, caps),
                                ostream_iterator<string>(cout, " "));
        cout << '\n';

        int         values[] = {1, 2, 3, 4, 5};
        vector<int> squares;

        transform(values, values + 5, values,
                                back_inserter(squares), multiplies<int>());

        copy(squares.begin(), squares.end(),
                                ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    /*
        Displays:
            ALPHA BRAVO CHARLEY
            1 4 9 16 25
    */
