    #include <iterator>

    class OutputIterator:
          public std::iterator<std::output_iterator_tag, int>
    {
        int d_value;

        public:
            OutputIterator(int init);

// standard:
            bool operator==(OutputIterator const &other) const;
            bool operator!=(OutputIterator const &other) const;
            int &operator*();
            OutputIterator &operator++();

// consider:
            int *operator->();
    };

OutputIterator::OutputIterator(int init)
:
    d_value(init)
{}

bool OutputIterator::operator!=(OutputIterator const &other) const
{
    return d_value != other.d_value;
}

bool OutputIterator::operator==(OutputIterator const &other) const
{
    return d_value == other.d_value;
}

OutputIterator &OutputIterator::operator++()
{
    return *this;
}

int &OutputIterator::operator*() 
{
    return d_value;
}
