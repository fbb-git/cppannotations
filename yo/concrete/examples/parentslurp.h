    #include "fork.h"
    #include "pipe.h"
    #include <unistd.h>
//CLASS
    class ParentSlurp: public Fork
    {
        Pipe    d_pipe;

        protected:
            virtual void childRedirections();
            virtual void parentRedirections();
            virtual void childProcess();
            virtual void parentProcess();
    };
//=

//CHILDREDIR
    inline void ParentSlurp::childRedirections()
    {
        d_pipe.writtenBy(STDOUT_FILENO);
    }
//=
//PARENTREDIR
    inline void ParentSlurp::parentRedirections()
    {
        d_pipe.readFrom(STDIN_FILENO);
    }
//=
//CHILDPROC
    inline void ParentSlurp::childProcess()
    {
        execl("/bin/ls", "/bin/ls", static_cast<char *>(0));
    }
//=
