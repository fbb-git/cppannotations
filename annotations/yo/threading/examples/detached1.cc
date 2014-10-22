#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void action()
{
    while (true)
    {
        cout << "Hello from detached" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main()
{
    thread t(action);
    t.detach();

    this_thread::sleep_for(chrono::seconds(4));
}
