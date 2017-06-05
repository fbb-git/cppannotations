#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

// waarom werkt clone() in de CC niet? Omdat bij de vector's
// push_back(Derived1()) de CC wordt aangeroepen, en niet other.clone(),
// terwijl 't niet duidelijk is hoe
// je in de CC clone() kunt gebruiken. *this = *other->clone() werkt
// niet.

class Base
{
    public:
        Base()
        {
            cout << "Base() " << ++s_n << "\n";
        }
        virtual ~Base()
        {
            std::cout << "~Base() << s_n--\n";
        }
        Base(Base const &other)
        {
            std::cout << "Base(Base const &)\n";
        }

        virtual Base *clone() const
        {
            std::cout << "Base clone()\n";
            return new Base();
        }
};

class Derived1: public Base
{
    public:
        Derived1()
        {
            std::cout << "Derived1()\n";
        }
        Derived1(Derived1 const &other)
        {
            std::cout << "Derived1(Derived1)\n";
        }
        ~Derived1()
        {
            std::cout << "~Derived1()\n";
        }
        virtual Base *clone() const
        {
            std::cout << "Derived1::clone()\n";
            return new Derived1(*this);
        }
};

class BWrap
{
    Base *d_bp;

    public:
        BWrap()
        :
            d_bp(new Base())
        {}
        BWrap(Base const &bp)
        :
            d_bp(bp.clone())
        {}
        BWrap(Base const *bp)
        :
            d_bp(bp->clone())
        {}
        ~BWrap()
        {
            destroy();
        }
        BWrap(BWrap const &other)
        {
            copy(other);
        }
        BWrap &operator=(BWrap const &other)
        {
            if (this != &other)
            {
                destroy();
                copy(other);
            }
            return *this;
        }

        Base &base() const
        {
            return *d_bp;
        }
    private:
        void destroy()
        {
            delete d_bp;
        }
        void copy(BWrap const &other)
        {
            d_bp = other.d_bp->clone();
        }
};

int main()
{
    vector<Base> bv{ 1 };
    cout << "==\n";

    Derived1 d1;
    cout << "==\n";

    bv.push_back(d1);
    cout << "==\n";
/*
    vector<BWrap> vb;
    cout << "==\n";

    vb.push_back(Derived1());
    cout << "==\n";

    vector<BWrap> vb2{ vb };
    cout << "==\n";

/ *
    Derived1 d1;
    vb.push_back(d1);
    cout << "==\n";

    Derived1 dp = &vb[0].ref();
    cout << dp << '\n';
    cout << "==\n";

    vb[0] = Base{};
    cout << "==\n";

    cout << typeid(vb[0].base()).name() << '\n';
    cout << typeid(vb[1].base()).name() << '\n';
    cout << "==\n";
*/
}
