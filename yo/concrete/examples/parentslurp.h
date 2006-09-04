    #include "fork.h"
    #include "pipe.h"
    #include <unistd.h>
//HEAD
    class ParentSlurp: public Fork
    {
        Pipe    d_pipe;
//=
        protected:
//CHILDREDIR
            virtual void childRedirections()
            {
                d_pipe.writtenBy(STDOUT_FILENO);
            }
//=
//PARENTREDIR
            virtual void parentRedirections()
            {
                d_pipe.readFrom(STDIN_FILENO);
            }
//=
//CHILDPROC
            virtual void childProcess()
            {
                execl("/bin/ls", "/bin/ls", 0);
            }
//=
            virtual void parentProcess();
    };
