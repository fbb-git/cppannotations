    #include <iostream>
    #include "message.h"
    #include "warning.h"
    using namespace std;

    void initialExceptionHandler(Exception const *e)
    {
        cout << *e << endl;         // show the plain-text information

        if
        (
            !dynamic_cast<MessageException const *>(e)
            &&
            !dynamic_cast<WarningException const *>(e)
        )
            throw;                  // Pass on other types of Exceptions

        e->process();               // Process a message or a warning
        delete e;
    }
