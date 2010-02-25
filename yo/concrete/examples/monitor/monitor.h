    #include <string>
    #include <map>

	#include <memory>

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
            TEXT,
            sizeofCommands
        };

        typedef std::map<int, std::shared_ptr<Child>> MapIntChild;

        friend class Find;
        class Find
        {
            int     d_nr;
            public:
                Find(int nr);
                bool operator()(MapIntChild::value_type &vt) const;
        };

        Selector    d_selector;
        int         d_nr;
        MapIntChild d_child;

        static void (Monitor::*s_handler[])(int, std::string const &);
        static int s_initialize;

        public:
            enum Done
            {};

            Monitor();
            void run();

        private:
            static void killChild(MapIntChild::value_type it);
            static int initialize();

            Commands    next(int *value, std::string *line);
            void    processInput();
            void    processChild(int fd);

            void    createNewChild(int, std::string const &);
            void    exiting(int = 0, std::string const &msg = std::string());
            void    sendChild(int value, std::string const &line);
            void    stopChild(int value, std::string const &);
            void    unknown(int, std::string const &);
    };
//=

//CONS
    inline Monitor::Monitor()
    :
        d_nr(0)
    {}
//=

//FINDIMP
    inline Monitor::Find::Find(int nr)
    :
        d_nr(nr)
    {}
    inline bool Monitor::Find::operator()(MapIntChild::value_type &vt) const
    {
        return d_nr == vt.second->nr();
    }
//=
