    #include <iostream>
    using namespace std;

    class Base
    {
        protected:
            void hello()
            {
                cout << "base hello\n";
            }
        public:
            void process()
            {
                hello();
            }
    };
    class Derived: public Base
    {
        protected:
            void hello()
            {
                cout << "derived hello\n";
            }
    };
    int main()
    {
        Derived derived;

        derived.process();
    }
