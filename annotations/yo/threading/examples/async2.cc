#include <iostream>
#include <future>

//code
void fun()
{
    std::cerr << "    hello from fun\n";
}

std::future<void> asyncCall(char const *label)
{
    std::cerr << label << " async call starts\n";
    auto ret = std::async(fun);
    std::cerr << label << " async call ends\n";
    return ret;
}

int main()
{
    asyncCall("First")
    asyncCall("Second");
}
//=

