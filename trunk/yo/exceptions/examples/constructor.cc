    #include <iostream>
    using namespace std;
//INCOMPLETE
    class Incomplete
    {
        public:
            Incomplete()
            {
                cerr << "Allocated some memory\n";
                throw 0;
            }
            ~Incomplete()
            {
                cerr << "Destroying the allocated memory\n";
            }
    };
//=
//MAIN
    int main()
    {
        try
        {
            cerr << "Creating `Incomplete' object\n";
            Incomplete();
            cerr << "Object constructed\n";
        }
        catch(...)
        {
            cerr << "Caught exception\n";
        }
    }
//=
