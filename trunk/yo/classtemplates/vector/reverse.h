    template <typename Type>
    class reverse_iter
    {
        public:
            explicit reverse_iter(Type *x)
            :
                current(x)
            {}
            Type &operator*() const
            {
                Type
                    *tmp = current;
                return (*--tmp);
            }
            Type *operator->() const
            {
                return &(operator*());
            }
            reverse_iter<Type>& operator++()
            {
                --current;
                return (*this);
            }
            reverse_iter<Type> operator++(int)
            {
                reverse_iter<Type>
                    tmp(current--);
                return (tmp);
            }
            bool operator!=(reverse_iter<Type> const &other)
            {
                return (current != other.current);
            }
        private:
            Type
                *current;
    };

        typedef reverse_iter<Type> reverse_iterator;

            reverse_iterator rbegin()
            {
                return (reverse_iterator(finish));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(data));
            }
