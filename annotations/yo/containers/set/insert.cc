#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
    set<int>
        object;

    pair<set<int>::iterator, bool>
        result = object.insert(set<int>::value_type(4));

    cout << "Element " << *result.first << " was " <<
        (result.second ? "" : "not ") << "inserted\n";

    result = object.insert(set<int>::value_type(4));

    cout << "Element " << *result.first << " was " <<
        (result.second ? "" : "not ") << "inserted\n";
}
