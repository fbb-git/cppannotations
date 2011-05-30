//CLASS
    class Fork
    {
        int d_pid;

        public:
            virtual ~Fork();
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
