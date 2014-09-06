#include <iostream>
#include <future>

using namespace std;

void fun()
{
    cerr << "    hello from fun\n";
}

struct Result
{
    void operator()();
};

//future<void> asyncCall(char const *label)
future<
    result_of<
        Result()
    >::type
> asyncCall(char const *label)
{
    cerr << label << " async call starts\n";
    auto ret = async(fun);
    cerr << label << " async call ends\n";
    return ret;
}

int main()
{
    asyncCall("First");
    asyncCall("Second");
}
