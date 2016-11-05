    class Binary
    {
        public:
            Binary();
            Binary(int value);

            Binary &operator+=(Binary const &other);

        private:
            void add(Binary const &other);

        friend Binary operator+(Binary const &lhs, Binary const &rhs);
    };

    Binary operator+(Binary const &lhs, Binary const &rhs)
    {
        Binary tmp(lhs);
        tmp.add(rhs);
        return tmp;
    }
