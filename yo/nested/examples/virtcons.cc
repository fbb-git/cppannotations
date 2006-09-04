    #include <iostream>
    #include <vector>
    #include <typeinfo>

    class Clonable
    {
        public:
            class Base
            {
                public:
                    virtual ~Base()
                    {}
                    virtual Base *clone() const = 0;
            };

        private:
            Base *d_bp;

        public:
            Clonable()
            :
                d_bp(0)
            {}
            ~Clonable()
            {
                delete d_bp;
            }
            Clonable(Clonable const &other)
            {
                copy(other);
            }
            Clonable &operator=(Clonable const &other)
            {
                if (this != &other)
                {
                    delete d_bp;
                    copy(other);
                }
                return *this;
            }

            // New for virtual constructions:
            Clonable(Base const &bp)
            {
                d_bp = bp.clone();      // allows initialization from
            }                           // Base and derived objects
            Base &get() const
            {
                return *d_bp;
            }

        private:
            void copy(Clonable const &other)
            {
                if ((d_bp = other.d_bp))
                    d_bp = d_bp->clone();
            }
    };

    class Derived1: public Clonable::Base
    {
        public:
            ~Derived1()
            {
                std::cout << "~Derived1() called\n";
            }
            virtual Clonable::Base *clone() const
            {
                return new Derived1(*this);
            }
    };

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
