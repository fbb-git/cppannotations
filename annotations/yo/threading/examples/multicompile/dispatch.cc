#include "main.ih"

bool dispatch(string const &line)
{
    if (line.empty())
        return false;

    g_workforce.reduce();
    
    Task task(line, PackagedTask(compile));

    push(task.result());

    if (g_done.load())
        return false;

    g_taskQ.push(move(task));

    g_worker.increase();

    return true;
}
