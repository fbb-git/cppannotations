    #include <string>
    #include <map>
    #include "../selector.h"
    #include "child.h"
//CLASS
    class Monitor
    {
        enum Commands
        {
            UNKNOWN,
            START,
            EXIT,
            STOP,
            TEXT
        };

        static void (Monitor::*s_handler[])(int, std::string const &);

        Selector                d_selector;
        int                     d_nr;
        std::map<int, Child *>  d_child;
//=
        public:
//CONS
            Monitor()
            :
                d_nr(0)
            {}
//=
            void run();

        private:
            static void waitForChild(int signum);
            static void killChild(std::map<int, Child *>::value_type it);

            Commands    next(int *value, std::string *line);
            void    processInput();
            void    processChild(int fd);

            void    createNewChild(int, std::string const &);
            void    exiting(int = 0, std::string const & = std::string());
            void    sendChild(int value, std::string const &line);
            void    stopChild(int value, std::string const &);
            void    unknown(int, std::string const &);
//FIND
            class Find
            {
                int     d_nr;
                public:
                    Find(int nr)
                    :
                        d_nr(nr)
                    {}
                    bool operator()(std::map<int, Child *>::value_type &vt)
                                                                        const
                    {
                        return d_nr == vt.second->nr();
                    }
            };
//=
    };
