#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    using namespace placeholders;

    vector<int> vi {1, 9, 2, 8, 3, 7, 4, 6, 5};

    cout << count_if(vi.begin(), vi.end(), 
            bind(greater<int>(), _1, 6)) << '\n';

    cout << count_if(vi.begin(), vi.end(), 
            bind(greater<int>(), 6, _1)) << '\n';
}
