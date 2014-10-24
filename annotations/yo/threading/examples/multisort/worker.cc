#include "main.ih"

//code
void worker()
{
    while (true)
    {
        g_worker.wait();      // wait for action

        partition(g_workQ.popFront());
        g_workforce.notify_all();

        lock_guard<mutex> lk(g_taskMutex);
        g_taskCondition.notify_one();
    }
}
//=
