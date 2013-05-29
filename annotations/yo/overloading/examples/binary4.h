    class Binary
    {
        public:
            Binary();
            Binary(int value);
            Binary(Binary &&tmp) = default;             // or roll your own

            Binary &operator+=(Binary const &other);    // see the text
    };

    Binary operator+(Binary const &lhs, Binary const &rhs)
    {
        Binary tmp(lhs);
        return operator+(std::move(tmp), rhs);
    }

    Binary operator+(Binary &&lhs, Binary const &rhs)
    {
        return lhs += rhs;
    }
