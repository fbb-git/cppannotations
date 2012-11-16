#include <vector>
#include <iostream>
#include <typeinfo>

using namespace std;

int main()
try
{
    vector<int> vi;

//    vi[0] = 12;             // segfaults
    vi.at(0) = 12;          // throws an exception
}
catch (std::exception const &exc)
{
    cerr << typeid(exc).name() << ' ' << exc.what() << '\n';
}
