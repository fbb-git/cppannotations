#include "main.ih"

void worker(int nr)
{
    string line;

    Task task;

    while (true)
    {
        g_worker.reduce();

        {
            lock_guard<mutex> lk(g_taskQMutex);
            task = move(g_taskQ.front());
            g_taskQ.pop();
        }

        task();

        g_workforce.increase();
    }
}





