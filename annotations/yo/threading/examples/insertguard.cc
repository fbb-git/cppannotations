#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>

using namespace std;

ifstream in;
mutex ioMutex;

bool nLine(int nr)
{
   lock_guard<mutex> lg(ioMutex);

    string line;
    if (not getline(in, line))
        return false;

    cout << nr << ": " << line << endl;

    return true;
}

void nio(int nr)
{
    while (nLine(nr))
        this_thread::sleep_for(chrono::nanoseconds(1));
}


int main(int argc, char **argv)
{
    in.open(argv[1]);

    thread t1(nio, 1);
    thread t2(nio, 2);
    thread t3(nio, 3);
    thread t4(nio, 4);

//    thread t1(io, ref(in), ref(ioMutex));
//    thread t2(io, ref(in), ref(ioMutex));
//    thread t3(io, ref(in), ref(ioMutex));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

