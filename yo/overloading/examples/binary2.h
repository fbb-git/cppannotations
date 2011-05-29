    class Binary
    {
        public:
            Binary();
            Binary(int value);
            Binary operator+(Binary const &rvalue);

            Binary &operator+=(Binary const &other);
    };

    Binary operator+(Binary const &lhs, Binary const &rhs);
