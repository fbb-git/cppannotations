#include <memory>
#include <iostream>
using namespace std;

typedef shared_ptr<int> si;
int main()
{
    si ip(new int(12));

    cout << ip.unique() << endl;

    si ip2(ip);

    cout << ip.unique() << endl;

    si ip3 = ip;
    si ip4;
    cout << *ip << ip.use_count() << endl;

    return 0;
}
