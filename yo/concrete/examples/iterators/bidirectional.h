    #include <iterator>

    class BidirectionalIterator:
          public std::iterator<std::bidirectional_iterator_tag, int>
    {
        int d_value;

        public:
            BidirectionalIterator(int init);

// standard:
            bool operator==(BidirectionalIterator const &other) const;
            bool operator!=(BidirectionalIterator const &other) const;
            int &operator*();
            BidirectionalIterator &operator++();

// required:
            BidirectionalIterator &operator--();

// consider:
            int *operator->();
    };

BidirectionalIterator::BidirectionalIterator(int init)
:
    d_value(init)
{}

bool BidirectionalIterator::operator!=(BidirectionalIterator const &other) const
{
    return d_value != other.d_value;
}

bool BidirectionalIterator::operator==(BidirectionalIterator const &other) const
{
    return d_value == other.d_value;
}

BidirectionalIterator &BidirectionalIterator::operator++()
{
    return *this;
}

BidirectionalIterator &BidirectionalIterator::operator--()
{
    return *this;
}

int &BidirectionalIterator::operator*() 
{
    return d_value;
}

