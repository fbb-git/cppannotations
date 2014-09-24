#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//code

int value;
mutex valueMutex;
mutex coutMutex;

void fun1()
{
    lock_guard<mutex> lg1(coutMutex);
    cout << "fun 1 locks cout\n";

    lock_guard<mutex> lg2(valueMutex);
    cout << "fun 1 locks value\n";
}

void fun2()
{
    lock_guard<mutex> lg1(valueMutex);
    cerr << "fun 2 locks value\n";

    lock_guard<mutex> lg2(coutMutex);
    cout << "fun 2 locks cout\n";
}

int main()
{
    thread t1(fun1);
    fun2();
    t1.join();
}

//=
    
