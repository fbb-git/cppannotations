#include <iostream>
#include <future>

//code
bool fun()
{
    return std::cerr << "    hello from fun\n";
}
int exceptionalFun()
{
    throw std::exception();
}

int main()
try
{
    auto fut1 = std::async(std::launch::async, fun);
    auto fut2 = std::async(std::launch::async, exceptionalFun);

    std::cerr << "fun returned " << std::boolalpha << fut1.get() << '\n';
    std::cerr << "exceptionalFun did not return " << fut2.get() << '\n';
}
catch (...)
{
    std::cerr << "caught exception thrown by exceptionalFun\n";
}
//=
