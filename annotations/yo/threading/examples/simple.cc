#include <unistd.h>
#include <iostream>
#include <future>

using namespace std;

bool stop;

void dots()
{
    while (not stop)
    {
        cout.put('.').flush();
        sleep(1);
    }
}

int main()
{
    cout << "Press 'enter' to end this program" << endl;
    auto ret = async(std::launch::async, dots);
    cin.ignore(10, '\n');
    stop = true;
}
