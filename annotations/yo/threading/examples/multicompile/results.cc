#include "main.ih"

void results()
{
    while (newResult())
    {
        Result result = g_resultQ.front().get();

        cerr << result.display;
        if (not result.ok)
            return;

        g_resultQ.pop();
    }
}





