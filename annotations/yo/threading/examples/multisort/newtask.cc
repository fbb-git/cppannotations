#include "main.ih"

//code
bool newTask()
{
    bool done;

    unique_lock<mutex> lk(g_taskMutex);
    while ((done = g_taskQ.empty()) && wip())
        g_taskCondition.wait(lk);

    return not done;
}
//=
