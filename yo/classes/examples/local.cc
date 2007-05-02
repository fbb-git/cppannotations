#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    static size_t staticValue = 0;

    class Local
    {
        int d_argc;             // non-static data members OK

        public:
            enum                // enums OK
            { 
                value = 5 
            };
            Local(int argc)     // constructors and member functions OK
            :                   // in-class implementation required
                d_argc(argc)    
            {                   
                                // global data: accessible
                cout << "Local constructor\n";
                                // static function variables: accessible
                staticValue += 5;
            }
            static void hello() // static member functions: OK
            {
                cout << "hello world\n";
            }
    };

    Local::hello();             // call Local static member

    Local loc(argc);            // define object of a local class.

    return 0;
}
