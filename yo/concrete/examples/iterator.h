    #ifndef INCLUDED_ITERATOR_H_
    #define INCLUDED_ITERATOR_H_

//HEAD
    #include <iterator>

    template <typename Class, typename BaseIterator, typename Type>
    class RandomPtrIterator:
          public std::iterator<std::random_access_iterator_tag, Type>
    {
        friend RandomPtrIterator<Class, BaseIterator, Type> Class::begin();
        friend RandomPtrIterator<Class, BaseIterator, Type> Class::end();

        BaseIterator d_current;

        RandomPtrIterator(BaseIterator const &current);

        public:
            bool operator!=(RandomPtrIterator const &other) const;
            int operator-(RandomPtrIterator const &rhs) const;
            RandomPtrIterator const operator+(int step) const;
            Type &operator*() const;
            bool operator<(RandomPtrIterator const &other) const;
            RandomPtrIterator &operator--();
            RandomPtrIterator const operator--(int);
            RandomPtrIterator &operator++();
            RandomPtrIterator const operator++(int);
            bool operator==(RandomPtrIterator const &other) const;
            RandomPtrIterator const operator-(int step) const;
            RandomPtrIterator &operator-=(int step);
            RandomPtrIterator &operator+=(int step);
            Type *operator->() const;
    };

    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type>::RandomPtrIterator(
                                    BaseIterator const &current)
    :
        d_current(current)
    {}
//=

    template <typename Class, typename BaseIterator, typename Type>
    bool RandomPtrIterator<Class, BaseIterator, Type>::operator!=(
                                    RandomPtrIterator const &other) const
    {
        return d_current != other.d_current;
    }
    template <typename Class, typename BaseIterator, typename Type>
    int RandomPtrIterator<Class, BaseIterator, Type>::operator-(
                                    RandomPtrIterator const &rhs) const
    {
        return d_current - rhs.d_current;
    }
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type> const
    RandomPtrIterator<Class, BaseIterator, Type>::operator+(int step) const
    {
        return RandomPtrIterator(d_current + step);
    }
//OP*
    template <typename Class, typename BaseIterator, typename Type>
    Type &RandomPtrIterator<Class, BaseIterator, Type>::operator*() const
    {
        return **d_current;
    }
//=
//CMP
    template <typename Class, typename BaseIterator, typename Type>
    bool RandomPtrIterator<Class, BaseIterator, Type>::operator<(
                                    RandomPtrIterator const &other) const
    {
        return **d_current < **other.d_current;
    }
//=
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type>
    &RandomPtrIterator<Class, BaseIterator, Type>::operator--()
    {
        --d_current;
        return *this;
    }
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator <Class, BaseIterator, Type> const
    RandomPtrIterator<Class, BaseIterator, Type>::operator--(int)
    {
        return RandomPtrIterator(d_current--);
    }
//INC
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type>
    &RandomPtrIterator<Class, BaseIterator, Type>::operator++()
    {
        ++d_current;
        return *this;
    }
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type> const
    RandomPtrIterator<Class, BaseIterator, Type>::operator++(int)
    {
        return RandomPtrIterator(d_current++);
    }
//=
    template <typename Class, typename BaseIterator, typename Type>
    bool RandomPtrIterator<Class, BaseIterator, Type>::operator==(
                                    RandomPtrIterator const &other) const
    {
        return d_current == other.d_current;
    }
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type> const
    RandomPtrIterator<Class, BaseIterator, Type>::operator-(int step) const
    {
        return RandomPtrIterator(d_current - step);
    }
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type>
    &RandomPtrIterator<Class, BaseIterator, Type>::operator-=(int step)
    {
        d_current -= step;
        return *this;
    }
    template <typename Class, typename BaseIterator, typename Type>
    RandomPtrIterator<Class, BaseIterator, Type>
    &RandomPtrIterator<Class, BaseIterator, Type>::operator+=(int step)
    {
        d_current += step;
        return *this;
    }
    template <typename Class, typename BaseIterator, typename Type>
    Type *RandomPtrIterator<Class, BaseIterator, Type>::operator->() const
    {
        return *d_current;
    }

    #endif
