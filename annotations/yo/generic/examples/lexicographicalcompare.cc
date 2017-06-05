    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;

    class CaseString
    {
        public:
            bool operator()(string const &first,
                            string const &second) const
            {
                return strcasecmp(first.c_str(), second.c_str()) < 0;
            }
    };
    int main()
    {
        string word1 = "hello";
        string word2 = "help";

        cout << word1 << " is " <<
            (
                lexicographical_compare(word1.begin(), word1.end(),
                                        word2.begin(), word2.end()) ?
                    "before "
                :
                    "beyond or at "
            ) <<
            word2 << " in the alphabet\n";

        cout << word1 << " is " <<
            (
                lexicographical_compare(word1.begin(), word1.end(),
                                        word1.begin(), word1.end()) ?
                    "before "
                :
                    "beyond or at "
            ) <<
            word1 << " in the alphabet\n";

        cout << word2 << " is " <<
            (
                lexicographical_compare(word2.begin(), word2.end(),
                                        word1.begin(), word1.end()) ?
                    "before "
                :
                    "beyond or at "
            ) <<
            word1 << " in the alphabet\n";

        string one[] = {"alpha", "bravo", "charley"};
        string two[] = {"ALPHA", "BRAVO", "DELTA"};

        copy(one, one + 3, ostream_iterator<string>{ cout, " " });
        cout << " is ordered " <<
            (
                lexicographical_compare(one, one + 3,
                                        two, two + 3, CaseString{}) ?
                    "before "
                :
                    "beyond or at "
            );
        copy(two, two + 3, ostream_iterator<string>{ cout, " " });
        cout << "\n"
            "using case-insensitive comparisons.\n";
    }
    /*
        Displays:
            hello is before help in the alphabet
            hello is beyond or at hello in the alphabet
            help is beyond or at hello in the alphabet
            alpha bravo charley  is ordered before ALPHA BRAVO DELTA
            using case-insensitive comparisons.
    */
