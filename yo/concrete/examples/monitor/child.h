    #include "../pipe.h"
    #include "../fork.h"
    #include "../selector.h"

//HEAD
    class Child: public Fork
    {
        Pipe                d_in;
        Pipe                d_out;

        int         d_parentReadFd;
        int         d_parentWriteFd;
        int         d_nr;
//=
        public:
//CONS
            Child(int nr)
            :
                d_nr(nr)
            {}
//=
//PIPES
            int readFd()
            {
                return d_parentReadFd;
            }
            int writeFd()
            {
                return d_parentWriteFd;
            }
//=
//PIDNR
            int pid()
            {
                return Fork::pid();
            }
            int nr()
            {
                return d_nr;
            }
//=
            virtual void childRedirections();
            virtual void parentRedirections();
            virtual void childProcess();
            virtual void parentProcess()
            {}
    };
