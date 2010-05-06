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

//
//
//    void initialExceptionHandler(Exception const *e)
//    {
//        cout << *e << '\n';         // show the plain-text information
//
//        if
//        (
//            !dynamic_cast<MessageException const *>(e)
//            &&
//            !dynamic_cast<WarningException const *>(e)
//        )
//            throw;                  // Pass on other types of Exceptions
//
//        e->process();               // Process a message or a warning
//        delete e;
//    }
