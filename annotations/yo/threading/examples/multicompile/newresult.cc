#include "main.ih"

//code
bool newResult()
{
    unique_lock<mutex> lk(g_resultQMutex);

    while
    (
        (
            g_resultQ.empty()
            &&
            g_workforce.size() != g_sizeofWorkforce
        )
        ||
        not g_ready.load()
    )
        g_resultCond.wait(lk);

    return not g_resultQ.empty();
}
//=
