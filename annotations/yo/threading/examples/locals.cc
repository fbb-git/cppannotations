#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void threadFun(std::string const &text)
{
    for (size_t iter = 1; iter != 6; ++iter)
    {
        std::cout << text << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::thread safeLocal()
{
    std::string text = "hello world";
    return std::thread(threadFun, std::string(text));
}

int main()
{
    std::thread local(safeLocal());
    std::cout << "safeLocal has ended\n";
    local.join();
}
