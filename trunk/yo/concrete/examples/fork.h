//CLASS
    class Fork
    {
        int d_pid;

        public:
            virtual ~Fork() = default;
            void fork();

        protected:
            int pid() const;
            int waitForChild();                 // returns the status

        private:
            virtual void childRedirections();
            virtual void parentRedirections();

            virtual void childProcess() = 0;    // pure virtual members
            virtual void parentProcess() = 0;
    };
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
