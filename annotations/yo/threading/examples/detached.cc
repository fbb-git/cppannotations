#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

void add(int const &p1, int const &p2)
{
    this_thread::sleep_for(milliseconds(200));
    cerr << p1 << " + " << p2 << " = " << (p1 + p2) << '\n';
}

void run()
{
    int v1 = 10;
    int v2 = 20;

//  thread(add, ref(v1), ref(v2)).detach();     // DON'T DO THIS
    thread(add, int(v1), int(v2)).detach();     // this is OK: own copies
}

void oops()
{
    int v1 = 0;
    int v2 = 0;
}

int main()
{
    run();
    oops();
    this_thread::sleep_for(seconds(1));
}
