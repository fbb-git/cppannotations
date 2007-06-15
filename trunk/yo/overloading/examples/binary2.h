    class Binary
    {
        public:
            Binary();
            Binary(int value);
            Binary const operator+(Binary const &rvalue);

            Binary &operator+=(Binary const &other);
    };

    Binary const operator+(Binary const &l_hand, Binary const &r_hand);
