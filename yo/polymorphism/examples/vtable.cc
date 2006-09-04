    class Base
    {
        public:
            virtual void member()
            {}
    };

    class Derived
    {
        public:
            virtual void member();      // only declared
    };

    int main()
    {
        Derived d;  // Will compile, since all members were declared.
                    // Linking will fail, since we don't have the
                    // implementation of Derived::member()
    }
