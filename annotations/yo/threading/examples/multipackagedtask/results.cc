#include "main.ih"

void results()
{
    while (true)
    {
        unique_lock<mutex> lk(g_resultQMutex);
        while (g_resultQ.empty())
            g_resultCond.wait(lk);

        string const &result = g_resultQ.front().get();

        if (not result.empty())
        {
            if (result != "done")
                cerr << result;
            return;
        }
        g_resultQ.pop();
    }
}
