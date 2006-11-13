    #include "../pipe.h"
    #include "../fork.h"
    #include "../selector.h"

       #include <sys/types.h>
       #include <signal.h>
       #include <sys/wait.h>

    #include <iostream>

//CLASS
    class Child: public Fork
    {
        Pipe                d_in;
        Pipe                d_out;

        int         d_parentReadFd;
        int         d_parentWriteFd;
        int         d_nr;

        public:
            Child(int nr);
            virtual ~Child();
            int readFd() const;
            int writeFd() const;
            int pid() const;
            int nr() const;
            virtual void childRedirections();
            virtual void parentRedirections();
            virtual void childProcess();
            virtual void parentProcess();
    };
//=

//CONS
    inline Child::Child(int nr)
    :
        d_nr(nr)
    {}
//=
//PIPES
    inline int Child::readFd() const
    {
        return d_parentReadFd;
    }
    inline int Child::writeFd() const
    {
        return d_parentWriteFd;
    }
//=
//PIDNR
    inline int Child::pid() const
    {
        return Fork::pid();
    }
    inline int Child::nr() const
    {
        return d_nr;
    }
//=
    inline void Child::parentProcess()
    {}
