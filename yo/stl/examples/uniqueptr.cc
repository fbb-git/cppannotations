#include <utility>
#include <iostream>
using namespace std;

//typedef unique_ptr<int> up;
int main()
{
    unique_ptr<int> ip(new int(12));

    return 0;
}
