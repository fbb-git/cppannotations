    #include <iterator>

    class RandomIterator:
          public std::iterator<std::random_access_iterator_tag, int>
    {
        int d_value;

        public:
            RandomIterator(int init);

// standard:
            bool operator==(RandomIterator const &other) const;
            bool operator!=(RandomIterator const &other) const;
            int &operator*();
            RandomIterator &operator++();

// required:
            int operator-(RandomIterator const &rhs) const;
            RandomIterator operator+(int step) const;
            RandomIterator operator-(int step) const;
            bool operator<(RandomIterator const &other) const;

// consider:
            int *operator->() const;
            RandomIterator &operator--();
            RandomIterator operator--(int);
            RandomIterator operator++(int);
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

bool RandomIterator::operator==(RandomIterator const &other) const
{
    return d_value == other.d_value;
}

bool RandomIterator::operator<(RandomIterator const &other) const
{
    return d_value < other.d_value;
}

int RandomIterator::operator-(RandomIterator const &rhs) const
{
    return 0;
}

RandomIterator RandomIterator::operator+(int step) const
{
    return *this;
}

RandomIterator RandomIterator::operator-(int step) const
{
    return *this;
}

RandomIterator &RandomIterator::operator--()
{
    return *this;
}

RandomIterator &RandomIterator::operator++()
{
    return *this;
}

int &RandomIterator::operator*()
{
    return d_value;
}
