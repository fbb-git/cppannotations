#include <iostream>
#include <tuple>
using namespace std;

// The Aux struct receives 
//  1. an index that reduces to zero initially representing the number of
//      elements in a tuple (int t_size); 
//  2. the tuple itself (tuple, typename Tuple)
//  3. the address of the function to call (fun, typename Fun)
//  4. the first argument to the function (received from the wrapper's
//     function call operator (arg, typename ArgType))
//  5. Any other series of arguments (params, typename ... Params)

template <  int size, 
            typename Tuple, 
            typename Fun,
            typename ArgType,
            typename ... Params>
struct Aux
{
    typedef typename tuple_element<size - 1, Tuple>::type ElType;

    inline Aux(Tuple &&tuple, Fun fun, ArgType &&arg, Params && ... params)
    {
        Aux<size - 1, Tuple &&, Fun, ArgType &&, ElType &&, Params && ...>
        (
            forward<Tuple>(tuple), 
            fun,
            forward<ArgType>(arg),
            forward<ElType>(get<size - 1>(tuple)), 
            forward<Params>(params) ...);
    }
};
    

// When the index has reduced to 0 the function is called, receiving arg and
// all params parameters.

template <
            typename Tuple, 
            typename Fun,
            typename ArgType,
            typename ... Params>
struct Aux<0, Tuple, Fun, ArgType, Params ...>
{
    inline Aux(Tuple &&tuple, Fun fun, ArgType &&arg, Params && ... params)
    {
        fun(forward<ArgType>(arg), forward<Params>(params) ...);
    }
};

template <typename Fun, typename ... Params>
class Wrapper
{
    template <  int size, 
            typename Tuple, 
            typename Fn,
            typename ArgType,
            typename ... Parms>
    friend struct Aux;

    Fun d_fun;
    std::tuple<Params ...> d_tuple;

    public:
        Wrapper(Fun fun, Params && ... params)
        :
            d_fun(fun),
            d_tuple(std::forward<Params>(params) ...)
        {}

        template <typename ArgType>
        void operator()(ArgType &&param)
        {
            Aux<tuple_size<tuple<Params ...>>::value, 
                tuple<Params ...>, 
                Fun, 
                ArgType                
                >
                (d_tuple, d_fun, param);
        }
};

void fun(int &x, ostream &out)
{
    out << "Value is: " << x << '\n';
    ++x;
}

int main()
{
    int x = 5;
    Wrapper<void (*)(int &, ostream &), ostream &> wrapper(fun, cout);

    wrapper(x);

    std::cout << "Now: " << x << '\n';
}


