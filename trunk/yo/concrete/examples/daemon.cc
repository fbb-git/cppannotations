    #include <iostream>
    #include <unistd.h>
    #include "fork.h"

    class Daemon: public Fork
    {
        public:
            virtual void parentProcess()        // the parent does nothing.
            {}

            virtual void childProcess()
            {
                sleep(3);                       // actions taken by the child
                                                // just a message...
                std::cout << "Hello from the child process\n";
                exit (0);                       // The child process exits.
            }
    };

    int main()
    {
        Daemon daemon;

        daemon.fork();          // program immediately returns
        return 0;
    }

    /*
        Generated output:
    The next command prompt, then after 3 seconds:
    Hello from the child process
    */
