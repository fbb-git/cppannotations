    #include <iterator>

    class InputIterator:
          public std::iterator<std::input_iterator_tag, int>
    {
        int d_value;

        public:
            InputIterator(int init);

// standard:
            bool operator==(InputIterator const &other) const;
            bool operator!=(InputIterator const &other) const;
            int const &operator*() const;
            InputIterator &operator++();

// consider:
            int const *operator->() const;
    };

InputIterator::InputIterator(int init)
:
    d_value(init)
{}

bool InputIterator::operator!=(InputIterator const &other) const
{
    return d_value != other.d_value;
}

bool InputIterator::operator==(InputIterator const &other) const
{
    return d_value == other.d_value;
}

InputIterator &InputIterator::operator++()
{
    return *this;
}

int const &InputIterator::operator*() const
{
    return d_value;
}
