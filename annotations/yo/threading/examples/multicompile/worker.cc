#include "main.ih"

//code
void worker()
{
    Task task;

    while (true)
    {
        g_worker.reduce();

        g_taskQ.popFront(task);
        task();

        g_workforce.increase();
    }
}
//=
