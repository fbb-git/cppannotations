#include "main.ih"

void push(shared_future<string> const &sharedResult)
{
    lock_guard<mutex> lk(g_resultQMutex);
    g_resultQ.push(sharedResult);
    g_resultCond.notify_one();
}
