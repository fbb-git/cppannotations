    #ifndef _INCLUDED_ITERATOR_H_
    #define _INCLUDED_ITERATOR_H_

//HEAD
    #include <iterator>

    template <typename Class, typename BaseIterator, typename Type>
    class RandomPtrIterator:
          public std::iterator<std::random_access_iterator_tag, Type>
    {
        friend RandomPtrIterator<Class, BaseIterator, Type> Class::begin();
        friend RandomPtrIterator<Class, BaseIterator, Type> Class::end();

        BaseIterator d_current;

        RandomPtrIterator(BaseIterator const &current)
        :
            d_current(current)
        {}
//=
        public:
            bool operator!=(RandomPtrIterator const &other) const
            {
                return d_current != other.d_current;
            }
            int operator-(RandomPtrIterator const &rhs) const
            {
                return d_current - rhs.d_current;
            }
            RandomPtrIterator const operator+(int step) const
            {
                return RandomPtrIterator(d_current + step);
            }
//OP*
            Type &operator*() const
            {
                return **d_current;
            }
//=
//CMP
            bool operator<(RandomPtrIterator const &other) const
            {
                return **d_current < **other.d_current;
            }
//=
            RandomPtrIterator &operator--()
            {
                --d_current;
                return *this;
            }
            RandomPtrIterator const operator--(int)
            {
                return RandomPtrIterator(d_current--);
            }
            RandomPtrIterator &operator++()
            {
                ++d_current;
                return *this;
            }
            RandomPtrIterator const operator++(int)
            {
                return RandomPtrIterator(d_current++);
            }
            bool operator==(RandomPtrIterator const &other) const
            {
                return d_current == other.d_current;
            }
            RandomPtrIterator const operator-(int step) const
            {
                return RandomPtrIterator(d_current - step);
            }
            RandomPtrIterator &operator-=(int step)
            {
                d_current -= step;
                return *this;
            }
            RandomPtrIterator &operator+=(int step)
            {
                d_current += step;
                return *this;
            }
            Type *operator->() const
            {
                return *d_current;
            }
    };

    #endif
