    #include <iostream>
    using namespace std;

    class Informer
    {
        public:
            ~Informer()
            {
                cout << "destructor called\n";
            }
    };

    class Wrapper
    {
        Informer *d_i;

        public:
            Wrapper()
            :
                d_i(new Informer())
            {}
            ~Wrapper()
            {
                delete d_i;
            }
    };

    int main()
    {
        delete[] new Informer *[4];    // memory leak: no destructor called

        cout << "===========\n";

        delete[] new Wrapper[4];       // ok: 4 x destructor called
    }
    /*
        Generated output:
    ===========
    destructor called
    destructor called
    destructor called
    destructor called
    */
