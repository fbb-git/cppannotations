#include "main.ih"

string compile(string const &line)
{
    string command("/usr/bin/g++ --std=c++11 -c " + line);
    
    CmdFork cmdFork(command);
    cmdFork.fork();

    string ret;

    if (cmdFork.childExit() != 0)
    {
        g_done = true;
        ret = cmdFork.childOutput();
    }

    return ret;
}

    
