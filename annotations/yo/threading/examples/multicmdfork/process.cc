#include "main.ih"

void process(int nr)
{
    string line;
    while (true)
    {
        g_worker.wait();
        {
            lock_guard<mutex> lk(g_qsMutex);
            line = g_qs.front();
            g_qs.pop();
        }

        if (line == "q")
        {
            g_workforce.notify_all();
            return;
        }

        string command("/usr/bin/g++ --std=c++11 -c " + line);

        CmdFork cmdFork(command);
        cmdFork.fork();

        cout << "Worker " << nr << ": " << line << " returns " <<
                cmdFork.childExit() << '\n'
                << cmdFork.childOutput() << '\n';

        g_workforce.notify_all();
    }
}
