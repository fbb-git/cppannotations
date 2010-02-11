#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

// The Aux struct receives 
//  1. an index that reduces to zero initially representing the number of
//      elements in a tuple (int t_size); 
//  2. the tuple itself (tuple, typename Tuple)
//  3. the address of the function to call (fun, typename Fun)
//  4. the first argument to the function (received from the wrapper's
//     function call operator (arg, typename ArgType))
//  5. Any other series of arguments (params, typename ... Params)

namespace FBB
{

namespace IUO
{

template <  int size, 
            typename Tuple,
            typename Fun,
            typename ArgType,
            typename ... Params>
struct Wrap
{
    typedef typename std::tuple_element<size - 1, Tuple>::type ElType;

    inline Wrap(Tuple &&tuple, Fun fun, ArgType &&arg, Params && ... params)
    {
        Wrap<size - 1, Tuple, Fun, ArgType, ElType, Params ...>
        (
            std::forward<Tuple>(tuple), 
            fun,
            std::forward<ArgType>(arg),
            std::forward<ElType>(std::get<size - 1>(tuple)), 
            std::forward<Params>(params) ...);
    }
};
    

// When the index has reduced to 0 the function is called, receiving arg and
// all params parameters.

template <
            typename Tuple, 
            typename Fun,
            typename ArgType,
            typename ... Params>
struct Wrap<0, Tuple, Fun, ArgType, Params ...>
{
    inline Wrap(Tuple &&tuple, Fun fun, ArgType &&arg, Params && ... params)
    {
        fun(std::forward<ArgType>(arg), std::forward<Params>(params) ...);
    }
};

} // IUO

template <typename Fun, typename ... Params>
class Wrap
{
    template <  int size, 
            typename Tuple, 
            typename Fn,
            typename ArgType,
            typename ... Parms>
    friend struct IUO::Wrap;

    Fun d_fun;
    std::tuple<Params ...> d_tuple;
    
    public:
        Wrap(Fun fun, Params && ... params)
        :
            d_fun(fun),
            d_tuple(std::forward<Params>(params) ...)
        {}

        template <typename ArgType>
        void operator()(ArgType &&param)
        {
            IUO::Wrap<std::tuple_size<std::tuple<Params ...>>::value, 
                std::tuple<Params ...>, 
                Fun, 
                ArgType                
                >
                (d_tuple, d_fun, param);
        }

};

struct Wrapper
{
    template <typename Func, typename ... Param>
    static Wrap<Func, Param ...> 
        gen(Func fun, Param && ... param)
        {
            Wrap<Func, Param ...> 
                ret(fun, std::forward<Param>(param) ... );
            return ret;
        }
};

} // FBB

using namespace std;

using namespace FBB;

class Vector
{
    vector<int> d_v;

    public:

    Vector()
    :
        d_v({1, 2, 3, 4})
    {}

    void run(ostream &out)
    {
        int count = 0;
        for_each(d_v.begin(), d_v.end(), 
            Wrapper::gen(callfun, count, out));
        cout << "Number of calls: " << count << '\n';
    }

    private: 

    static void callfun(int v, int &count, ostream &o)
    {
        o << "Value is: " << v << '\n';
        ++count;
    }

};

int main()
{
    Vector v;
    v.run(cout);
}



