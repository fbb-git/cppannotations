    #include <iostream>
    using namespace std;
    
    class Base
    {
        public:
            void hello()
            {
                cout << "base hello\n";
            }
            void process()
            {
                hello();
            }
    };
    
    class Derived: public Base
    {
        public:
            void hello()
            {
                cout << "derived hello\n";
            }
    };
    
    int main()
    {
        Derived derived;
    
        derived.process();
        return 0;
    }
