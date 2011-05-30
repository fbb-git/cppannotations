    class Binary
    {
        public:
            Binary();
            Binary(int value);

            Binary &operator+=(Binary const &other);
    };

    Binary operator+(Binary const &lhs, Binary const &rhs)
    {
        Binary tmp(lhs);
        tmp += rhs;
        return tmp;
    }
