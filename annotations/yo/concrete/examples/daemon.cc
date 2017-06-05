    #include <iostream>
    #include <unistd.h>
    #include "fork.h"

    class Daemon: public Fork
    {
        virtual void parentProcess()        // the parent does nothing.
        {}
        virtual void childProcess()         // actions by the child
        {
            sleep(3);
                                            // just a message...
            std::cout << "Hello from the child process\n";
            throw 0;                        // The child process ends
        }
    };

    int main()
    try
    {
        Daemon{}.fork();
    }
    catch(...)
    {}

    /*
        Generated output:
    The next command prompt, then after 3 seconds:
    Hello from the child process
    */
