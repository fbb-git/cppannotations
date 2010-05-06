    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <time.h>
    #include <iterator>
    using namespace std;

    int randomValue(int remaining)
    {
        return rand() % remaining;
    }
    class RandomGenerator
    {
        public:
            RandomGenerator()
            {
                srand(time(0));
            }
            int operator()(int remaining) const
            {
                return randomValue(remaining);
            }
    };
    void show(string *begin, string *end)
    {
        copy(begin, end, ostream_iterator<string>(cout, " "));
        cout << "\n\n";
    }
    int main()
    {
        string words[] =
                    { "kilo", "lima", "mike", "november", "oscar", "papa"};
        size_t const size = sizeof(words) / sizeof(string);

        cout << "Using Default Shuffle:\n";
        random_shuffle(words, words + size);
        show(words, words + size);

        cout << "Using RandomGenerator:\n";
        RandomGenerator rg;
        random_shuffle(words, words + size, rg);
        show(words, words + size);

        srand(time(0) << 1);
        cout << "Using the randomValue() function:\n";
        random_shuffle(words, words + size, randomValue);
        show(words, words + size);
    }
    /*
        Displays (for example):
            Using Default Shuffle:
            lima oscar mike november papa kilo

            Using RandomGenerator:
            kilo lima papa oscar mike november

            Using the randomValue() function:
            mike papa november kilo oscar lima
    */
