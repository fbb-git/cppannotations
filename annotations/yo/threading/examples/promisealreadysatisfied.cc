#include <future>
#include <iostream>

//code
int main()
{
    std::promise<int> promise;
    promise.set_value(15);
    promise.set_value(155);
}
//=
