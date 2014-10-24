#include "main.ih"

//code
bool dispatch(string const &line)
{
    if (line.empty())
        return true;

    if (g_done.load())
        return false;

    g_workforce.wait();
    newTask(line);
    g_worker.notify_all();
    return true;
}
//=
