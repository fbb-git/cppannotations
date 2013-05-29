    #include <iostream>
    #include <vector>
    #include <typeinfo>
    using namespace std;

    class Base
    {
        public:
            virtual ~Base()
            {}
            virtual Base *clone() const = 0;
    };

    class Clonable
    {
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


    class Derived1: public Base
    {
        public:
            Derived1()
            {}
            Derived1(Derived1 const &other)
            {}
            ~Derived1()
            {}
            virtual Base *clone() const
            {
                return new Derived1(*this);
            }
    };

    int main()
    {
        vector<Clonable> bv;
        {
            Derived1 d1;

            bv.push_back(d1);
        }
        cout << "==\n";
        cout << typeid(bv[0].get()).name() << '\n';
        cout << "==\n";

        vector<Clonable> v2(bv);
        cout << typeid(v2[0].get()).name() << '\n';
        cout << "==\n";

    }
