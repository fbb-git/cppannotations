#include <tuple>
#include <iostream>
#include <algorithm>

#include <bobcat/typetrait>

template <typename ... Types>
struct Multi
{
    std::tuple<Types ...> d_tup;

    Multi(Types && ... types)
    :
        d_tup(std::forward<Types>(types) ...)
    {}
};

template <typename Result, typename Opnd, typename ... Cntxt>
struct Wrapper
{
    mutable std::tuple<Cntxt ...> d_cntxt;

    Result (*d_fun)(Opnd, std::tuple<Cntxt ...>& );

    Wrapper(Result fun(Opnd, std::tuple<Cntxt ...> &), Cntxt && ... cntxt)
    :
        d_cntxt(std::forward<Cntxt>(cntxt) ...),
        d_fun(fun)
    {}

    Result operator()(Opnd &&opnd) const
    {
        return d_fun(std::forward<Opnd>(opnd), d_cntxt);
    }
};


using namespace std;


void handle(std::string const &str, tuple<size_t &, ostream &> &tup)
{
    ++get<0>(tup);
    get<1>(tup) << "Saw: " << str << '\n';
}

int main(int argc, char **argv)
{
    Multi<int, double, int> multi(3, 12.5, 5);

    size_t count = 0;

    for_each(argv, argv + argc, Wrapper<void, std::string const &,
                               size_t &, ostream &>(handle, count, cout));

    cout << "========> " << count << '\n';
    cout << get<1>(multi.d_tup) << '\n';
}
