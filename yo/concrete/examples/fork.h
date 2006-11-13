//CLASS
    class Fork
    {
        int d_pid;

        public:
            virtual ~Fork();
            void fork();

        protected:
            int pid() const;
            virtual void childRedirections();
            virtual void parentRedirections();
            virtual void childProcess() = 0;    // both must be implemented
            virtual void parentProcess() = 0;
            int waitForChild();                 // returns the status
    };
//=
//DES
    inline Fork::~Fork()
    {}
//=
//PID
    inline int Fork::pid() const
    {
        return d_pid;
    }
//=
//REDIRECT
    inline void Fork::childRedirections()
    {}
    inline void Fork::parentRedirections()
    {}
//=
