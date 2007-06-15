    template <typename Type1>
    class Outer
    {
        public:
            template <typename Type2>                  // template class
            class Inner;

            template <typename Type>                   // template function
            Type process(Type const &p1, Type const &p2);
    };

                                                    // template class member
    template <typename Type1> template <typename Type2>

    class Outer<Type1>::Inner                       // no Type2 with `Inner'
    {
        public:
            Type1
                variable1;
            Type2
                variable2;
    };
                                                    // template function member
    template <typename Type1> template <typename Type>
    Type Outer<Type1>::process(Type const &p1, Type const &p2)
    {
        Type
            result;
        return result;
    }
