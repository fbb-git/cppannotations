#include <iostream>
#include <future>

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

//code
int main()
{
    auto ret1 = asyncCall("First");
    auto ret2 = asyncCall("Second");

    ret1.get();
    ret2.get();
}
//=



