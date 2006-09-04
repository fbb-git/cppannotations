    #include <iostream>

    class Base
    {
        public:
            virtual ~Base()
            {}
            virtual char const *toString()
            {
                return "Base::toString() called";
            }
    };

    class Derived1: public Base
    {};

    class Derived2: public Base
    {};

    void process(Base &b)
    {
        try
        {
            std::cout << dynamic_cast<Derived1 &>(b).toString() << std::endl;
        }
        catch (std::bad_cast)
        {}

        try
        {
            std::cout << dynamic_cast<Derived2 &>(b).toString() << std::endl;
        }
        catch (std::bad_cast)
        {
            std::cout << "Bad cast to Derived2\n";
        }
    }

    int main()
    {
        Derived1 d;

        process(d);
    }
    /*
        Generated output:

        Base::toString() called
        Bad cast to Derived2
    */
