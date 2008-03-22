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
                            public output_iterator
            {
                friend class Vector2<Type>;

                public:
                    Type &operator*() const;
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
                                // requirements output iterator
        copy(istream_iterator<int>(cin), istream_iterator<int>(), vi.rbegin());
    }
