#include "main.ih"

//code
void worker()
{
    Task task;

    while (true)
    {
        g_worker.wait();

        g_taskQ.popFront(task);
        task();

        g_workforce.notify_all();
    }
}
//=
