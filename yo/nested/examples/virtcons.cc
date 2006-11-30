    #include <iostream>
    #include <vector>
    #include <typeinfo>

    class Clonable
    {
        public:
            class Base
            {
                public:
                    virtual ~Base();
                    virtual Base *clone() const = 0;
            };

        private:
            Base *d_bp;

        public:
            Clonable();
            ~Clonable();
            Clonable(Clonable const &other);
            Clonable &operator=(Clonable const &other);

            // New for virtual constructions:
            Clonable(Base const &bp);
            Base &get() const;

        private:
            void copy(Clonable const &other);
    };


    inline Clonable::Base::~Base()
    {}

    inline Clonable::Clonable()
    :
        d_bp(0)
    {}
    inline Clonable::~Clonable()
    {
        delete d_bp;
    }
    inline Clonable::Clonable(Clonable const &other)
    {
        copy(other);
    }
    inline Clonable &Clonable::operator=(Clonable const &other)
    {
        if (this != &other)
        {
            delete d_bp;
            copy(other);
        }
        return *this;
    }

    inline Clonable::Clonable(Base const &bp)
    {
        d_bp = bp.clone();      // allows initialization from
    }                           // Base and derived objects

    inline Clonable::Base &Clonable::get() const
    {
        return *d_bp;
    }

    inline void Clonable::copy(Clonable const &other)
    {
        if ((d_bp = other.d_bp))
            d_bp = d_bp->clone();
    }

    class Derived1: public Clonable::Base
    {
        public:
            ~Derived1();
            virtual Clonable::Base *clone() const;
    };

    inline Derived1::~Derived1()
    {
        std::cout << "~Derived1() called\n";
    }
    inline Clonable::Base *Derived1::clone() const
    {
        return new Derived1(*this);
    }

    using namespace std;

    int main()
    {
        vector<Clonable> bv;

        bv.push_back(Derived1());
        cout << "==\n";

        cout << typeid(bv[0].get()).name() << endl;
        cout << "==\n";

        vector<Clonable> v2(bv);
        cout << typeid(v2[0].get()).name() << endl;
        cout << "==\n";
    }
