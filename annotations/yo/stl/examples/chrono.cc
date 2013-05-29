#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
    cout << chrono::duration<int, ratio<1>>(30).count() << endl;
    cout << chrono::duration<int, milli>(30).count() << endl;

    cout <<
//      chrono::system_clock::to_time_t
//      (
//            chrono::system_clock::from_time_t(time(0))

        chrono::system_clock::to_time_t
        (
            chrono::time_point
            <
                chrono::system_clock,
                chrono::duration
                <
                    int,
                    ratio<1>
                >
            >
            (
                //chrono::duration<int, ratio<1>>(time(0))
                chrono::minutes(time(0)/60)
            )
        ) <<
        endl;
}
