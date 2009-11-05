    #include <iostream>
    using namespace std;

    class StringStore   // partially implemented
    {
        public:
            ~StringStore();
    };

    inline StringStore::~StringStore()
    {
        cout << "destructor called\n";
    }

    class Wrapper
    {
        StringStore *d_stringStore;

        public:
            Wrapper();
            ~Wrapper();
    };

    inline Wrapper::Wrapper()
    :
        d_stringStore(new StringStore())
    {}
    inline Wrapper::~Wrapper()
    {
        delete d_stringStore;
    }

    int main()
    {
        delete[] new StringStore *[4]; // memory leak: no destructor called
        cout << "===========\n";
        delete[] new Wrapper[4];       // OK: 4 x destructor called
    }
    /*
        Generated output:
    ===========
    destructor called
    destructor called
    destructor called
    destructor called
    */
