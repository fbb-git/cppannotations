    #include <iterator>

    class ForwardIterator:
          public std::iterator<std::forward_iterator_tag, int>
    {
        int d_value;

        public:
            ForwardIterator(int init);

// standard:
            bool operator==(ForwardIterator const &other) const;
            bool operator!=(ForwardIterator const &other) const;
            int &operator*();
            ForwardIterator &operator++();

// consider:
            int *operator->();
    };

ForwardIterator::ForwardIterator(int init)
:
    d_value(init)
{}

bool ForwardIterator::operator!=(ForwardIterator const &other) const
{
    return d_value != other.d_value;
}

bool ForwardIterator::operator==(ForwardIterator const &other) const
{
    return d_value == other.d_value;
}

ForwardIterator &ForwardIterator::operator++()
{
    return *this;
}

int &ForwardIterator::operator*()
{
    return d_value;
}
