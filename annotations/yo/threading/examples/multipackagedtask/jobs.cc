#include "main.ih"

void jobs()
{
    string line;

    while (getline(cin, line) && not line.empty())
    {
        if (not dispatch(line))
            break;
    }

    promise<string> finalResult;
    finalResult.set_value("done");

    lock_guard<mutex> lk(g_resultQMutex);
    g_resultQ.push(finalResult.get_future().share());
    g_resultCond.notify_one();
}


