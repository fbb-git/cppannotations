#include "main.ih"

//code
void worker()
{
    while (true)
    {
        g_worker.reduce();      // wait for action

        partition(g_workQ.popFront());
        g_workforce.increase();

        lock_guard<mutex> lk(g_taskMutex);
        g_taskCondition.notify_one();
    }
}
//=
