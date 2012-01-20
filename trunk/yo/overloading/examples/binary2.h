    class Binary
    {
        public:
            Binary();
            Binary(int value);

            Binary &operator+=(Binary const &rhs);
    };

    Binary operator+(Binary const &lhs, Binary const &rhs);
