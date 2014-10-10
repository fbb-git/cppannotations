#include "main.ih"

void dispatch()
{
    string line;
    while (getline(cin, line) && not line.empty())
    {
        g_workforce.reduce();

        Task task(line, PackagedTask(compile));

        {
            lock_guard<mutex> lk(g_resultQMutex);

            g_resultQ.push(task.result());
        }

        {
            lock_guard<mutex> lk(g_taskQMutex);
            {
                lock_guard<mutex> lk(g_doneMutex);
                if (g_done)
                    break;
            }
            g_taskQ.push(move(task));
        }
    
        cerr << line << '\n';
        g_worker.increase();
    }

    promise<string> finalResult;
    finalResult.set_value("done");

    {
        lock_guard<mutex> lk(g_resultQMutex);
        g_resultQ.push(finalResult.get_future().share());
        g_resultCond.notify_one();
    }
}


