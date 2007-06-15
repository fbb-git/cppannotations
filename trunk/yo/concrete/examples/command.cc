    #include <iostream>
    #include <sstream>
    #include <string>

    enum
    {
        UNKNOWN,
        START,
        EXIT,
        STOP,
        TEXT
    };

    int next(int &value, std::string &line)
    {
        if (!getline(std::cin, line))
            throw "Command::next(): reading cin failed";

        if (line == "start")
            return START;

        if (line == "exit")
            return EXIT;

        if (line.find("stop") == 0)
        {
            std::istringstream istr(line.substr(4));
            istr >> value;
            return !istr ? UNKNOWN : STOP;
        }

        std::istringstream istr(line.c_str());
        istr >> value;
        if (istr)
        {
            getline(istr, line);
            return
        line = istr.str();

        return !istr ? UNKNOWN : TEXT;
    }

    int main()
    {
        while (true)
        {
            std::string line;
            int         value;

            std::cout << "? " << std::flush;

            switch (next(value, line))
            {
                case START:
                    std::cout << "start\n";
                break;

                case EXIT:
                    std::cout << "exit\n";
                    return 0;
                break;

                case STOP:
                    std::cout << "stop " << value << "\n";
                break;

                case TEXT:
                    std::cout << "text: " << line << "\n";
                break;

                default:
                    std::cout << "unknown: " << line << "\n";
                break;
            }
        }
    }
