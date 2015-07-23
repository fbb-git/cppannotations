#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

template <typename Fun>
struct not_fn_
{
    Fun const &d_fun;

    not_fn_(Fun const &fun)
    :
        d_fun(fun)
    {}

    template <typename ... ParTypes>
    bool operator()(ParTypes && ...types)
    {
        return not d_fun(std::forward<ParTypes>(types)...);
    }
};

template <typename Fun>
not_fn_<Fun> not_fn(Fun const &fun)
{
    return not_fn_<Fun>(fun);
}

using namespace std;
using namespace placeholders;

//main
int main()
{
    vector<string> vs {"a", "a", "b"};
    string reftext {"b"};

    cout <<
        count_if(vs.begin(), vs.end(),
            bind(not_fn(equal_to<string>()), _1, reftext)) << '\n' <<
        count_if(vs.begin(), vs.end(),
            not_fn(bind(equal_to<string>(), _1, reftext))) << '\n';
}
//=
