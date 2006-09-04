    #include <string>
    #include <vector>
    #include <algorithm>

    class Command
    {
        std::string                 d_line;
        std::vector<std::string>    d_command;

        public:
            Command(unsigned n, char const **commands)
            {
                copy(commands, commands + n, back_inserter(d_command));
            }

            int next(std::string &line);
    };
