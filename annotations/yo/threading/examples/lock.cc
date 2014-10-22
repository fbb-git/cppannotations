#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

//code

int value;
mutex valueMutex;
mutex coutMutex;

void fun1()
{
    unique_lock<mutex> lg1(coutMutex, defer_lock);
    unique_lock<mutex> lg2(valueMutex, defer_lock);

    lock(lg1, lg2);

    cout << "fun 1 locks cout\n";
    cout << "fun 1 locks value\n";
}

void fun2()
{
    unique_lock<mutex> lg1(coutMutex, defer_lock);
    unique_lock<mutex> lg2(valueMutex, defer_lock);

    lock(lg2, lg1);

    cout << "fun 2 locks cout\n";
    cout << "fun 2 locks value\n";
}

int main()
{
    thread t1(fun1);
    thread t2(fun2);
    t1.join();
    t2.join();
}

//=
