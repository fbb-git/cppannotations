#include "cmdfork.ih"

void CmdFork::parentProcess()
{
    IFdStream fromChild(d_childOutput.readOnly());

           // read the child's output
    d_command.clear();

    string line;
    while (getline(fromChild, line))
        d_command += line + '\n';

    d_childExit = waitForChild();
}






