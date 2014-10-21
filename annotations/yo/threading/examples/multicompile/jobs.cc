#include "main.ih"

//code
void jobs()
{
    string line;
    while (getline(cin, line) && dispatch(line))
        ;

    g_ready = true;
    g_resultCond.notify_one();
}
//=

