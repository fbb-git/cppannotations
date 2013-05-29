    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <typeinfo>

// Base and its inline member:
    class Base
    {
        public:
            virtual ~Base();
            Base *clone() const;
        private:
            virtual Base *newCopy() const = 0;
    };
    inline Base *Base::clone() const
    {
        return newCopy();
    }

// Clonable and its inline members:
    class Clonable
    {
        Base *d_bp;

        public:
            Clonable();
            explicit Clonable(Base *base);
            ~Clonable();
            Clonable(Clonable const &other);
            Clonable(Clonable &&tmp);
            Clonable &operator=(Clonable const &other);
            Clonable &operator=(Clonable &&tmp);

            Base &base() const;
    };
    inline Clonable::Clonable()
    :
        d_bp(0)
    {}
    inline Clonable::Clonable(Base *bp)
    :
        d_bp(bp)
    {}
    inline Clonable::Clonable(Clonable const &other)
    :
        d_bp(other.d_bp->clone())
    {}
    inline Clonable::Clonable(Clonable &&tmp)
    :
        d_bp(tmp.d_bp)
    {
        tmp.d_bp = 0;
    }
    inline Clonable::~Clonable()
    {
        delete d_bp;
    }
    inline Base &Clonable::base() const
    {
        return *d_bp;
    }

// Derived and its inline member:
    class Derived1: public Base
    {
        public:
            ~Derived1();
        private:
            virtual Base *newCopy() const;
    };
    inline Base *Derived1::newCopy() const
    {
        return new Derived1(*this);
    }

// Members not implemented inline:
    Base::~Base()
    {}
    Clonable &Clonable::operator=(Clonable const &other)
    {
        Clonable tmp(other);
        std::swap(d_bp, tmp.d_bp);
        return *this;
    }
    Clonable &Clonable::operator=(Clonable &&tmp)
    {
        std::swap(d_bp, tmp.d_bp);
        return *this;
    }
    Derived1::~Derived1()
    {
        std::cout << "~Derived1() called\n";
    }

// The main function:
    using namespace std;

    int main()
    {
        vector<Clonable> bv;

        bv.push_back(Clonable(new Derived1()));
        cout << "bv[0].name: " << typeid(bv[0].base()).name() << '\n';

        vector<Clonable> v2(bv);
        cout << "v2[0].name: " << typeid(v2[0].base()).name() << '\n';
    }
    /*
        Output:
            bv[0].name: 8Derived1
            v2[0].name: 8Derived1
            ~Derived1() called
            ~Derived1() called
    */
