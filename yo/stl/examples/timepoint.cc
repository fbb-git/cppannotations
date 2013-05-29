#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
        // the current time
    time_point<system_clock> now(system_clock::now());

        // its value in seconds:
    cout << system_clock::to_time_t(now) << '\n';

        // now + two hours:
    cout << system_clock::to_time_t(now + hours(2)) << '\n';

        // define a time_point 1 hour after the epoch:
    time_point<system_clock> oneHrLater(hours(1));

        // show the epoch and the time in seconds of oneHrLater:
    cout << system_clock::to_time_t(time_point<system_clock>()) << ' ' <<
            system_clock::to_time_t(oneHrLater) << '\n';
}
