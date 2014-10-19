#include <iostream>
#include <bobcat/irandstream>

using namespace std;
using namespace FBB;

int main()
{
    IRandStream is(10000);

    for (int idx = 0; idx != 10000; )
    {
        size_t value;
        is >> value;
        cout << value << ' ';
        if (++idx % 10 == 0)
            cout << '\n';
    }
    cout << '\n';
}
