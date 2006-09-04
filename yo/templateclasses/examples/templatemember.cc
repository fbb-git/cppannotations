    template <typename Type1>
    class Outer
    {
        public:
            template <typename Type2>              // template class
            class Inner
            {
                public:
                    Type1
                        variable1;
                    Type2
                        variable2;
            };

            template <typename Type3>              // template function
            Type3 process(Type3 const &p1, Type3 const &p2)
            {
                Type3
                    result;

                return result;
            }
    };
