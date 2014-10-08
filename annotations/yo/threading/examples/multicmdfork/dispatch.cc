#include "main.ih"

void dispatch(string const &line)
{
    g_workforce.reduce();
    {
        lock_guard<mutex> lk(g_qsMutex);
        g_qs.push(line);
    }
    g_worker.increase();
}
