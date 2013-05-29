    #include <iostream>
    #include <iterator>
    #include "vector.h"

    template <typename Type>
    class Vector2: public Vector<Type>
    {
        public:
            Vector2()
            :
                Vector<Type>()
            {};
            Vector2(size_t n)
            :
                Vector<Type>(n)
            {}

            class reverse_iterator:
                            public input_iterator<Type, ptrdiff_t>
            {
                friend class Vector2<Type>;

                public:
                    bool operator==(reverse_iterator const &other) const;
                    Type const &operator*() const;
                    reverse_iterator &operator++();
                private:
                    reverse_iterator(Vector<Type> *vp);
                    reverse_iterator(Type *begin, Type *end);
            };

            reverse_iterator rbegin()
            {
                return reverse_iterator(this);
            }
            reverse_iterator rend()
            {
                return reverse_iterator(this->begin(), this->begin());
            }
    };

    int main()
    {
        Vector2<int>
            vi;
                                // requirements input iterator
        copy(vi.rbegin(), vi.rend(), ostream_iterator<int>(cout, " "));
    }
