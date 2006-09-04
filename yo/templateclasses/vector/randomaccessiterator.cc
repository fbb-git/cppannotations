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
            Vector2(unsigned n)
            :
                Vector<Type>(n)
            {}

            class reverse_iterator:
                            public random_access_iterator<Type, ptrdiff_t>
            {
                friend class Vector2<Type>;

                public:
                    Type &operator*() const;
                    bool operator==(reverse_iterator const &other) const;
                    reverse_iterator &operator++();
                    reverse_iterator operator++(int);
                    reverse_iterator &operator--();
                    reverse_iterator operator--(int);

                    reverse_iterator operator+(int step) const;
                    reverse_iterator operator-(int step) const;
                    int operator-(reverse_iterator const &other) const;

                    bool operator<(reverse_iterator const &other) const;
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
                                    // requirements random access iterator
                return reverse_iterator(this->begin(), this->begin());
            }
    };

    int main()
    {
        Vector2<int>
            vi;
                                // requirements random access iterator
        sort(vi.rbegin(), vi.rend());
    }
