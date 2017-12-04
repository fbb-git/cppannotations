#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//code
int main()
{
    auto lambda = [](auto lhs, auto rhs)
                {
                    return lhs + rhs;
                };

    vector<int> values {1, 2, 3, 4, 5};
    vector<string> text {"a", "b", "c", "d", "e"};

    cout <<
        accumulate(values.begin(), values.end(), 0, lambda) << '\n' <<
        accumulate(text.begin(), text.end(), string(), lambda) << '\n';
}
//=
