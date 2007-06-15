    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <time.h>
    #include <iterator>

    int randomValue(int remaining)
    {
        return static_cast<int>
                ( ((0.0 + remaining) * rand()) / (RAND_MAX + 1.0) );
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


    void show(std::string *begin, std::string *end)
    {
        std::copy(begin, end,
                        std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl << std::endl;
    }

    using namespace std;

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

        return 0;
    }
    /*
        Generated output (for example):

        Using Default Shuffle:
        lima oscar mike november papa kilo

        Using RandomGenerator:
        kilo lima papa oscar mike november

        Using the randomValue() function:
        mike papa november kilo oscar lima
    */
