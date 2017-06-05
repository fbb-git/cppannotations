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
                            public forward_iterator<Type, ptrdiff_t>
            {
                friend class Vector2<Type>;

                public:
                    Type &operator*() const;
                    reverse_iterator &operator++();
                    bool operator==(reverse_iterator const &other) const;
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
        Vector2<int> vi;
                                // requirements forward iterator
        remove(vi.rbegin(), vi.rend(), 12);
    }
