#include <iostream>
using namespace std;

//DRAWER
    class Drawer
    {
        unsigned d_nr;
        public:
            Drawer(unsigned nr)
            :
                d_nr(nr)
            {}
            ~Drawer()
            {
                cerr << "Drawer " << d_nr << " used\n";
                throw 0;
            }
    };
//=
//CUP1
    class Cupboard1
    {
        Drawer left;
        public:
            Cupboard1()
            :
                left(1)
            {}
    };
//=
//CUP2
    class Cupboard2
    {
        Drawer left;
        Drawer right;
        public:
            Cupboard2()
            :
                left(1),
                right(2)
            {}
    };
//=

//MAIN
    int main()
    {
        try
        {
            cerr << "Creating Cupboard1\n";
            Cupboard1();
            cerr << "Beyond Cupboard1 object\n";
        }
        catch (...)
        {
            cerr << "Cupboard1 behaves as expected\n";
        }
        try
        {
            cerr << "Creating Cupboard2\n";
            Cupboard2();
            cerr << "Beyond Cupboard2 object\n";
        }
        catch (...)
        {
            cerr << "Cupboard2 behaves as expected\n";
        }
    }
//=
