    #include "warning.h"
    #include "fatal.h"

    Exception::~Exception()
    {}

    using namespace std;

    int main(int argc, char **argv)
    try
    {
        try
        {
            if (argc == 1)
                throw Fatal("Missing Argument") ;
            else
                throw Warning("the argument is ignored");
        }
        catch (Exception const &e)
        {
            cout << e << '\n';
            e.handle();
        }
    }
    catch(...)
    {
        cout << "caught rethrown exception\n";
    }
