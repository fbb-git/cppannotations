    class Binary
    {
        public:
            Binary();
            Binary(int value);
                // copy and move constructors are available by default, or
                // they can be explicitly declared and implemented.

            Binary &operator+=(Binary const &other);    // see the text
    };

    inline Binary &&operator+(Binary &&lhs, Binary const &rhs)
    {
        return std::move(lhs += rhs);   // avoids copy/move construction
    }

    inline Binary &&operator+(Binary const &lhs, Binary const &rhs)
    {
        Binary tmp(lhs);
        return std::move(tmp) + rhs;
    }
