    #include <iterator>
    #include <istream>
    #include <ctime>
    #include <vector>
    #include <algorithm>

#if 1

//FUNCTION
    template <typename Type>
    class Storage
    {
        friend void basic();
        static size_t s_time;
        std::vector<Type> d_data;
        public:
            Storage();
    };
    template <typename Type>
    size_t Storage<Type>::s_time = 0;
    template <typename Type>
    Storage<Type>::Storage()
    {}

    void basic()
    {
        Storage<int>::s_time = time(0);
        Storage<double> storage;
        std::random_shuffle(storage.d_data.begin(), storage.d_data.end());
    }
//=

//    class Friend;         // SF.

//CLASS
    template <typename Type>
    class Composer
    {
        friend class Friend;
        std::vector<Type> d_data;
        public:
            Composer();
    };

    class Friend
    {
        Composer<int> d_ints;
        public:
            Friend(std::istream &input);
    };

    inline::Friend::Friend(std::istream &input)
    {
        std::copy(std::istream_iterator<int>(input),
                  std::istream_iterator<int>(),
                  back_inserter(d_ints.d_data));
    }
//=

#else

//MEMBER
    template <typename Type>
    class Composer;

    class Friend
    {
        Composer<int> *d_ints;
        public:
            Friend(std::istream &input);
            void randomizer();
    };

    template <typename Type>
    class Composer
    {
        friend void Friend::randomizer();
        std::vector<Type> d_data;
        public:
            Composer(std::istream &input)
            {
                std::copy(std::istream_iterator<int>(input),
                          std::istream_iterator<int>(),
                          back_inserter(d_data));
            }
    };

    inline Friend::Friend(std::istream &input)
    :
        d_ints(new Composer<int>(input))
    {}

    inline void Friend::randomizer()
    {
        std::random_shuffle(d_ints->d_data.begin(), d_ints->d_data.end());
    }
//=

#endif
