    #include <iterator>

    class RandomIterator:
          public std::iterator<std::random_access_iterator_tag, int>
    {
        int d_value;

        public:
            RandomIterator(int init);

            bool operator==(RandomIterator const &other) const;
            int operator-(RandomIterator const &rhs) const;
            RandomIterator operator+(int step) const;

            RandomIterator &operator--()
            int &operator*();
            int *operator->() const;
            bool operator<(RandomIterator const &other) const;
            RandomIterator operator--(int);
            RandomIterator &operator++();
            RandomIterator operator++(int);
            RandomIterator operator-(int step) const;
            RandomIterator &operator-=(int step);
            RandomIterator &operator+=(int step);
    };

RandomIterator::RandomIterator(int init)
:
    d_value(init)
{}

bool RandomIterator::operator!=(RandomIterator const &other) const
{
    return d_value != other.d_value;
}

int RandomIterator::operator-(RandomIterator const &rhs) const
{
    return 0;
}

RandomIterator &RandomIterator::operator--()
{
    return *this;
}

int &RandomIterator::operator*()
{
    return d_value;
}

