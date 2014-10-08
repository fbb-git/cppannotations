#include "cmdfork.ih"

void CmdFork::childRedirections()
{
    d_childOutput.writtenBy(STDERR_FILENO);
}
