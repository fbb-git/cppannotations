#include "childprocess.ih"

void ChildProcess::run()
{
    executeChildProcess();
    exit(-1);               // doProcess itself should stop
}
