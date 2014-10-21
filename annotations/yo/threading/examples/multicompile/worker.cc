#include "main.ih"

void worker(int nr)
{
    string line;

    Task task;

    while (true)
    {
        g_worker.reduce();

        g_taskQ.popFront(task);
        task();

        g_workforce.increase();
    }
}





