#include "main.ih"

//code
void results()
{
    while (newResult())
    {
        Result const &result = g_resultQ.front().get();

        cerr << result.display;
        if (not result.ok)
            return;

        g_resultQ.pop();
    }
}
//=
