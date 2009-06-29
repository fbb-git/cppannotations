#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

template <class T, class A1>
void factory(A1&& a1)
{
    new T(std::forward<A1>(a1));
}

struct Forward
{
    Forward() 
    {
        cout << "Cons\n";
    }
    Forward(Forward const &fwr)
    {
        cout << "L-value const reference\n";
    }
    Forward(Forward &fwr)
    {
        cout << "L-value reference\n";
    }
    Forward(Forward *fwr)
    {
        cout << "Pointer\n";
    }
    Forward(Forward const *fwr)
    {
        cout << "Const Pointer\n";
    }
    Forward(Forward &&fwr)
    {
        cout << "R-value reference\n";
    }
    static Forward make()
    {
        return Forward();
    }
};

template <typename... BaseClasses> 
class ClassName: public BaseClasses ...
{
    public:
        ClassName(BaseClasses && ... baseClasses)
        :
            BaseClasses(baseClasses) ... 
        {}
};

ClassName<string, vector<string>>
    object("wim", vector<string>(3));

int main()
{
    Forward f;
    Forward &f1 = f;
    Forward &&f2 = f;
    Forward const &f3 = f;

    factory<Forward>(f1);
    factory<Forward>(f3);
    factory<Forward>(&f1);
    factory<Forward>(&f3);
    factory<Forward>(Forward::make());
}







