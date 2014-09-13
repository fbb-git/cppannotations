#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void hello()
{
    std::cout << "hello world!\n";
}

void starter(thread &&tmp)
{
    tmp.join();
}

// an anonymous thread without destination var.
// is only started when its join member is called. With destination var.
// join is required.
int main()
{
//    thread &&thr = thread(hello);
    starter(thread(hello));
    cout << "before join\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
//    thr.join();
//    cout << "after join\n";
}
