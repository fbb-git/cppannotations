#include "main.ih"

//code
void scheduler()
{
    while (newTask())
    {
        g_workQ.rawPushFront(g_taskQ);

        g_workforce.wait();           // wait for a worker to be available
        g_worker.notify_all();            // activate a worker
    }
}
//=
