    #include <iostream>
    #include <string>
    #include <map>
    #include <sstream>

//HEAD
    class Handler: private std::map<std::string,
                            void (Handler::*)(std::string const &cmd)>
//=
    {
//STATIC
        static value_type s_cmds[];
        static value_type *const s_cmds_end;
//=
        public:
//CONS
            Handler()
            :
                std::map<std::string,
                            void (Handler::*)(std::string const &cmd)>
                (s_cmds, s_cmds_end)
            {}
//=
            void process(std::string const &line);
        private:
            void list(std::string const &line);
    };

    using namespace std;

    Handler::value_type Handler::s_cmds[] =
    {
        value_type("list", &Handler::list),
    };

    Handler::value_type *const Handler::s_cmds_end =
                        s_cmds +
                        sizeof(s_cmds) / sizeof(Handler::value_type);
//PROCESS
    void Handler::process(std::string const &line)
    {
        istringstream istr(line);
        string cmd;
        istr >> cmd;
        for (iterator it = begin(); it != end(); it++)
        {
            if (it->first.find(cmd) == 0)
            {
                (this->*it->second)(line);
                return;
            }
        }
        cout << "Unknown command: " << line << endl;
    }
//=
    void Handler::list(std::string const &line)
    {
        cout << "Handler::list() called using `" << line << "'\n";
    }

//MAIN
    int main()
    {
        string line;
        Handler cmd;

        while (getline(cin, line))
            cmd.process(line);
    }
//=
