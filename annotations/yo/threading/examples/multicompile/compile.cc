#include "main.ih"

//code
Result compile(string const &line)
{
    string command("/usr/bin/g++ -Wall --std=c++11 -c " + line);

    CmdFork cmdFork(command);
    cmdFork.fork();

    Result ret {cmdFork.childExit() == 0,
                line + "\n" + cmdFork.childOutput()};

    if (not ret.ok)
        g_done = true;

    return ret;
}
//=
