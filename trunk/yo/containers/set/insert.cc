#include <set>
#include <utility>

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

    return (0);
}
