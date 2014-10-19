#include "main.ih"

void worker(int nr)
{
    while (true)
    {
        g_worker.reduce();      // wait for action

        sorter(g_workQ.popFront());
        g_workforce.increase();

        lock_guard<mutex> lk(g_taskMutex);
        g_taskCondition.notify_one();
    }
}



