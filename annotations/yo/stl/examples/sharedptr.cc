#include <memory>
#include <iostream>
using namespace std;

typedef shared_ptr<int> si;
int main()
{
    si ip(new int(12));

    cout << ip.unique() << '\n';

    si ip2(ip);

    cout << ip.unique() << '\n';

    si ip3 = ip;
    si ip4;
    cout << *ip << ip.use_count() << '\n';

    return 0;
}
