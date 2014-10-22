#include "main.ih"

//code
void scheduler()
{
    while (newTask())
    {
        g_workQ.rawPushFront(g_taskQ);

        g_workforce.reduce();           // wait for a worker to be available
        g_worker.increase();            // activate a worker
    }
}
//=
