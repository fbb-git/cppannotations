#include <iostream>
#include <future>

using namespace std;

//code
void compute1(promise<int> &ref)
{
    ref.set_value(9);
}

int main()
{
    std::promise<int> p;
    std::thread(compute, ref(p)).detach();

    cout << p.get_future().get() << '\n';
}
//=
