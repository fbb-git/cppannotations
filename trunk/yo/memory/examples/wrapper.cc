    #include <iostream>
    using namespace std;

    class Strings   // partially implemented
    {
        public:
            ~Strings();
    };

    inline Strings::~Strings()
    {
        cout << "destructor called\n";
    }

    class Wrapper
    {
        Strings *d_strings;

        public:
            Wrapper();
            ~Wrapper();
    };

    inline Wrapper::Wrapper()
    :
        d_strings(new Strings())
    {}
    inline Wrapper::~Wrapper()
    {
        delete d_strings;
    }

    int main()
    {
        delete[] new Strings *[4]; // memory leak: no destructor called
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
