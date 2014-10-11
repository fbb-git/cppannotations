#include "main.ih"

bool dispatch(string const &line)
{
    g_workforce.reduce();

    Task task(line, PackagedTask(compile));

    {
        lock_guard<mutex> lk(g_resultQMutex);
        g_resultQ.push(task.result());
    }

    if (g_done.load())
        return false;

    g_taskQ.push(move(task));

    cerr << line << '\n';
    g_worker.increase();

    return true;
}
