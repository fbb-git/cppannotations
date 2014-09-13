#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    cout << system_clock::to_time_t(system_clock().now()) << '\n';
}
