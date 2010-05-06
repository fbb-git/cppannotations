    #include <iostream>

    class Base
    {
        public:
            virtual ~Base();
            virtual char const *toString();
    };
    inline char const *Base::toString()
    {
        return "Base::toString() called";
    }
    class Derived1: public Base
    {};
    class Derived2: public Base
    {};

    Base::~Base()
    {}
    void process(Base &b)
    {
        try
        {
            std::cout << dynamic_cast<Derived1 &>(b).toString() << '\n';
        }
        catch (std::bad_cast)
        {}
        try
        {
            std::cout << dynamic_cast<Derived2 &>(b).toString() << '\n';
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
