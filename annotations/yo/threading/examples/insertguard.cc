#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

bool oneLine(istream &in, mutex &mut, int nr)
{
   lock_guard<mutex> lg(mut);

    string line;
    if (not getline(in, line))
        return false;

    cout << nr << ": " << line << endl;

    return true;
}

void io(istream &in, mutex &mut, int nr)
{
    while (oneLine(in, mut, nr))
        this_thread::yield();
}

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    mutex ioMutex;

    thread t1(io, ref(in), ref(ioMutex), 1);
    thread t2(io, ref(in), ref(ioMutex), 2);
    thread t3(io, ref(in), ref(ioMutex), 3);

    t1.join();
    t2.join();
    t3.join();
}
