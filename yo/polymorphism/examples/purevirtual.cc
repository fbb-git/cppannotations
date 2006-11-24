#include <iostream>

class Base
{
    public:
        virtual ~Base();
        virtual void pure() = 0;
};

inline Base::~Base()
{}

inline void Base::pure()
{
    std::cout << "Base::pure() called\n";
}

class Derived: public Base
{
    public:
        virtual void pure();
};

inline void Derived::pure()
{
    Base::pure();
    std::cout << "Derived::pure() called\n";
}

int main()
{
    Derived derived;

    derived.pure();
    derived.Base::pure();

    Derived *dp = &derived;

    dp->pure();
    dp->Base::pure();
}
// Output:
//	Base::pure() called
//	Derived::pure() called
//	Base::pure() called
//	Base::pure() called
//	Derived::pure() called
//	Base::pure() called
