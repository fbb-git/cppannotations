    class Binary
    {
        public:
            Binary();
            Binary(int value);
            Binary const operator+(Binary const &rvalue);

            Binary &operator+=(Binary const &other);
    };

    Binary const operator+(Binary const &lhs, Binary const &rhs)
    {
        Binary tmp(lhs);
        tmp += rhs;
        return tmp;
    }
