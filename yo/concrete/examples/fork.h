//HEAD
    class Fork
    {
        int d_pid;
//=
        public:
//PUBLIC
            virtual ~Fork()
            {}
            void fork();
//=
        protected:
//PID
            int pid()
            {
                return d_pid;
            }
//=
//REDIRECT
            virtual void childRedirections()
            {}
            virtual void parentRedirections()
            {}
//=
//PURE
            virtual void childProcess() = 0;    // both must be implemented
            virtual void parentProcess() = 0;
//=
            int waitForChild();                 // returns the status
    };
