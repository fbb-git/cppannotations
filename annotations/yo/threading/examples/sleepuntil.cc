#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

void nowait()
{
    cerr << "hello ";
    this_thread::sleep_until(system_clock().now() - seconds(5));
    cerr << "world\n";
}

int main()
{
    thread(nowait).join();
}
