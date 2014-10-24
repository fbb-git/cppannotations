#include "main.ih"

void dispatch(string const &line)
{
    g_workforce.wait();
    {
        lock_guard<mutex> lk(g_qsMutex);
        g_qs.push(line);
    }
    g_worker.notify_all();
}
