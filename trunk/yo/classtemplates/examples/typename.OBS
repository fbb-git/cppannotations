#if 0
    template <typename T>
    class Outer
    {
        public:
            template <typename U>
            class Nested
            {
            };

        Nested<T> nested() const;
    };


    template <typename T>
    Outer<T>::Nested<T>
    Outer<T>::nested() const
    {
        return Nested<T>();
    }
#else
#if 1
     template <typename T>
    class Outer
    {
        public:
            class Nested
            {
            };

        Nested nested() const;
    };

    template <typename T>
//    typename
    Outer<T>::Nested
    Outer<T>::nested() const
    {
        return Nested();
    }
#else
    template <typename T>
    class Outer
    {
        public:
            class Nested
            {
            };

        Nested nested() const
        {
            return Nested();
        }
    };

#endif

#endif
