    class Binary
    {
        public:
            Binary();
            Binary(int value);
            Binary operator+(Binary const &rhs);
    };

    int main()
    {
        Binary b1;
        Binary b2(5);

        b1 = b2 + 3;            // 1
        b1 = 3 + b2;            // 2
    }
