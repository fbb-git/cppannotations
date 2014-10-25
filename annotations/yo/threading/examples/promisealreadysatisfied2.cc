#include <future>
#include <iostream>
#include <exception>

//code
int main()
{
    std::promise<int> promise;
    promise.set_value(15);
    promise.set_exception(std::make_exception_ptr(std::exception()));
}
//=
