    class iterator: public Iterator
    {
        friend class StringPtr;

        std::vector<std::string *>::iterator d_current;

        iterator(std::vector<std::string *>::iterator const &current)
        :
            d_current(current)
        {}

        public:
            iterator &operator--()
            {
                --d_current;
                return *this;
            }
            iterator const operator--(int)
            {
                return iterator(d_current--);
            }
            iterator &operator++()
            {
                ++d_current;
                return *this;
            }
            bool operator==(iterator const &other) const
            {
                return d_current == other.d_current;
            }
            bool operator!=(iterator const &other) const
            {
                return d_current != other.d_current;
            }
            int operator-(iterator const &rhs) const
            {
                return d_current - rhs.d_current;
            }
            std::string &operator*() const
            {
                return **d_current;
            }
            bool operator<(iterator const &other) const
            {
                return **d_current < **other.d_current;
            }
            iterator const operator+(int step) const
            {
                return iterator(d_current + step);
            }
            iterator const operator-(int step) const
            {
                return iterator(d_current - step);
            }

    // the following members are not used by sort(), but they
    // might come in handy in other situations:
            iterator &operator+=(int step)  // increment the iterator
            {                               // over `n' steps
                d_current += step;
                return *this;
            }
            iterator &operator-=(int step)  // decrement the iterator
            {                               // over `n' steps
                d_current -= step;
                return *this;
            }
            std::string *operator->() const // access the fields of the
            {                               // struct an iterator points
                return *d_current;          // to. E.g., it->length()
            }
    };
