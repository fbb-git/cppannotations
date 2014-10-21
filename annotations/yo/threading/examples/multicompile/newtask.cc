#include "main.ih"

//code
void newTask(string const &line)
{
    Task task(line, PackagedTask(compile));

    pushResultQ(task.result());
    g_taskQ.push(move(task));
}
//=
