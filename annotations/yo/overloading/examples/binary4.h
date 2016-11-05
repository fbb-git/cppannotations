    class Binary
    {
        public:
            Binary();
            Binary(int value);
                // copy and move constructors are available by default, or
                // they can be explicitly declared and implemented.

            Binary &operator+=(Binary const &other) &;    // see the text
            Binary &&operator+=(Binary const &other) &&; 
    };

    Binary operator+(Binary const &lhs, Binary const &rhs);
    Binary operator+(Binary &&lhs, Binary const &rhs);


