#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

vector<int> data;

void quicksort(vector<int>::iterator begin, vector<int>::iterator end)
try
{
    if (end - begin < 2)
        return;

    auto rhsBegin = partition(begin + 1, end, bind2nd(less<int>(), *begin));
    auto lhsEnd = rhsBegin - 1;

    swap(*begin, *lhsEnd);

    thread lhs(quicksort, begin, lhsEnd);
    thread rhs(quicksort, rhsBegin, end);

    lhs.join();
    rhs.join();
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}

int main()
{
    int value;
    while (cin >> value)
        data.push_back(value);

    quicksort(data.begin(), data.end());

    for (auto el: data)
        cout << el << ' ';
    cout << '\n';
}
