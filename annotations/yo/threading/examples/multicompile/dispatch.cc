#include "main.ih"

//code
bool dispatch(string const &line)
{
    if (line.empty())
        return true;

    if (g_done.load())
        return false;

    g_workforce.reduce();
    newTask(line);
    g_worker.increase();
    return true;
}
//=
