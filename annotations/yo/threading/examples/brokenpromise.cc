#include <future>
#include <iostream>

//code
std::future<int> fun()
{
    return std::promise<int>().get_future();
}

int main()
try
{
    fun().get();
}
catch (std::exception const &exc)
{
    std::cerr << exc.what() << '\n';
}
//=
