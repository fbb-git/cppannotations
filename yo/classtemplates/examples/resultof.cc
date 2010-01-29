#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename Class>
class Filter
{
    Class obj;
    public:
        template <typename Arg>
        typename std::result_of<Class(Arg)>::type
            operator()(Arg const &arg) const
            {
                return obj(arg);
            }
};


struct Convert      // if there's just one ReturnType operator()(...), simply
{                   // define  `typedef ReturnType type'
    template <typename Signature>
    struct result;

    double operator()(int x) const
    { 
        return 12.5; 
    }
    template <typename Class>
    struct result<Class(int)>
    {
        typedef double type;
    };

    string operator()(double x) const
    { 
        return string("hello world"); 
    }
    template <typename Class>
    struct result<Class(double)>
    {
        typedef string type;
    };
};

int main()
{
    Filter<Convert> fc;

    cout << fc(5.5).length() << '\n';
    cout << fc(5) << '\n';
}
