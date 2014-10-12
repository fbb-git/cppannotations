#include <future>
#include <iostream>

//code
int main()
{
    std::promise<int> promise;
    promise.get_future();
    promise.get_future();
}
//=



