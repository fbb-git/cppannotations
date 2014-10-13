#include <iostream>
#include <fstream>
#include <future>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

//code
mutex commandMutex;
condition_variable condition;
string command;
packaged_task<size_t (std::string const &)> task;

size_t length(string const &str)
{
    return str.length();
}

size_t file(string const &fname)
{
    ifstream in(fname);
    size_t nLines = 0;
    while (in.ignore(1000, '\n'))
        ++nLines;
    return nLines;
}

void run()
{
    while (true)
    {
        unique_lock<mutex> lk(commandMutex);
        while (command.empty())
            condition.wait(lk);

        task(command);
        command.clear();
    }
}

int main()
{
    thread(run).detach();

    while (true)
    {
        string line;
        if (not getline(cin, line) || line.empty())
            break;
        {
            lock_guard<mutex> lk(commandMutex);
            command = line.substr(1);
        }
        task =  packaged_task<size_t (string const &)>(
                    line[0] == 'l' ? length : file
                );
        auto result = task.get_future();
        condition.notify_one();
        cout << "Result of " << line << ": " << result.get() << '\n';
    }
}
//=
