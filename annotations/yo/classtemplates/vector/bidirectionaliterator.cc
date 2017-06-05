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
                            public bidirectional_iterator<Type, ptrdiff_t>
            {
                friend class Vector2<Type>;

                public:
                    Type &operator*() const;
                    bool operator==(reverse_iterator const &other) const;
                    reverse_iterator &operator++();
                    reverse_iterator operator++(int);
                    reverse_iterator &operator--();
                    reverse_iterator operator--(int);
                private:
                    reverse_iterator(Vector<Type> *vp);
                    reverse_iterator(Type *begin, Type *end);
            };

            reverse_iterator rbegin()
            {
                return reverse_iterator(this);
            }
            reverse_iterator rend()
            {                       // requirements bidirectional iterator
                return reverse_iterator(this->begin(), this->begin());
            }
    };

    int main()
    {
        Vector2<int> vi;
                                // requirements bidirectional iterator
        reverse(vi.rbegin(), vi.rend());
    }
