#include "main.ih"

void pushTask(Iter const &begin, Iter const &end)
{
    g_taskQ.push(Pair(begin, end));

    lock_guard<mutex> lk(g_taskMutex);
    g_taskCondition.notify_one();
}
