
// compile with 'g++ parentslurp.cc fork.cc waitforchild.cc pipe.cc'

    #include "fork.h"
    #include "pipe.h"
    #include <unistd.h>
//CLASS
    class ParentSlurp: public Fork
    {
        Pipe    d_pipe;

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
        execl("/bin/ls", "/bin/ls", 0);
    }
//=
