    #include "monitor.ih"

//INPUT
    void Monitor::processInput()
    {
        string line;
        int    value;
        Commands cmd = next(&value, &line);
        (this->*s_handler[cmd])(value, line);
    }
//=
//NEXT
    Monitor::Commands Monitor::next(int *value, string *line)
    {
        if (!getline(cin, *line))
            exiting(1, "Command::next(): reading cin failed");

        if (*line == "start")
            return START;

        if (*line == "exit" || *line == "quit")
        {
            *value = 0;
            return EXIT;
        }

        if (line->find("stop") == 0)
        {
            istringstream istr(line->substr(4));
            istr >> *value;
            return !istr ? UNKNOWN : STOP;
        }

        istringstream istr(line->c_str());
        istr >> *value;
        if (istr)
        {
            getline(istr, *line);
            return TEXT;
        }

        return UNKNOWN;
    }
//=
