#include <iostream>
#include <string>
#include <vector>

using namespace std;

//code
auto accumulate(auto const &container, auto function)
{
    auto accu = decltype(container[0]){};

    for (auto &value: container)
        accu = function(accu, value);

    return accu;
}

auto lambda = [](auto lhs, auto rhs)
            {
                return lhs + rhs;
            };

int main()
{
    vector<int> values  = {1, 2, 3, 4, 5};
    vector<string> text = {"a", "b", "c", "d", "e"};

    cout << accumulate(values,  lambda) << '\n' <<
            accumulate(text,    lambda) << '\n';
}
//=
