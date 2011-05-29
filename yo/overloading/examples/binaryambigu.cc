    class A;

    class B
    {
        public:
            B(A const &a);
    };

    class A
    {
        public:
            A();
            A(B const &b);
    };

    A operator+(A const &a, B const &b);
    B operator+(B const &b, A const &a);

    int main()
    {
        A a;

        a + a;
    };
