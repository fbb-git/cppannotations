#include "main.ih"

//code
void pushResultQ(shared_future<Result> const &sharedResult)
{
    lock_guard<mutex> lk(g_resultQMutex);
    g_resultQ.push(sharedResult);
    g_ready = true;
    g_resultCond.notify_one();
}
//=
