#include <future>
#include <iostream>

//code
int main()
{
    std::promise<int> promise;
    promise.set_value(15);
    
    auto fut = promise.get_future();
    auto shared1 = fut.share();

    std::cerr << "Result: " << shared1.get() << '\n';
              << "Result: " << shared1.get() << '\n';
              << "Valid: " << fut.valid() << '\n';

    auto shared2 = fut.share();

    std::cerr << "Result: " << shared2.get() << '\n';
              << "Result: " << shared2.get() << '\n';
}
//=
