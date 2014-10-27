#include <iostream>
using namespace std;

//code
void compute(int *ret)
{
    *ret = 9;
}

int main()
{
    int ret = 0;
    std::thread(compute2, &ret).detach();
    cout << ret << '\n';
}
//=
