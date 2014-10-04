#include <iostream>
#include <future>

int fun()
{
    std::cerr << "    hello from fun\n";
    return 12;
}

int indirect(std::future<int> &fut)
{
    std::cerr << "calling indirect to obtain fun's results\n";
    return fut.get();
}

int main()
{
    auto fut = std::async(fun);

    auto ret = std::async(std::launch::async, indirect, std::ref(fut));
    std::cerr << "receiving from fun: " << ret.get() << '\n';
}
