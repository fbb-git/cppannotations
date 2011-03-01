#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// The Aux struct receives
//  1. an index that reduces to zero initially representing the number of
//      elements in a tuple (int t_size);
//  2. the tuple itself (tuple, typename Tuple)
//  3. the address of the function to call (fun, typename Fun)
//  4. the first argument to the function (received from the wrapper's
//     function call operator (arg, typename Arg1))
//  5. Any other series of arguments (params, typename ... Params)

namespace FBB
{

namespace IUO
{

// ======================================================

// Wrap1<size, ... degenerates to Wrap1<0, .... Wrap1<0 calls the unary
// function, receiving its initial argument from the STL algorithm and
// optional other arguments from Wrap1 itself
//

template <  int size,
            typename Return, typename Tuple,
            typename Fun, typename Arg1, typename ... Params>
struct Wrap1
{
    typedef typename std::tuple_element<size - 1, Tuple>::type ElType;

    inline Wrap1(Return &ret,
                Tuple &&tuple, Fun fun, Arg1 &&arg, Params &&...params)
    {
        Wrap1<size - 1, Return, Tuple, Fun, Arg1, ElType, Params ...>
        (
            ret,
            std::forward<Tuple>(tuple),
            fun,
            std::forward<Arg1>(arg),
            std::forward<ElType>(std::get<size - 1>(tuple)),
            std::forward<Params>(params) ...
        );
    }
};

template < typename Return, typename Tuple,
           typename Fun, typename Arg1, typename ... Params>
struct Wrap1<0, Return, Tuple, Fun, Arg1, Params ...>
{
    inline Wrap1(Return &ret,
                Tuple &&tuple, Fun fun, Arg1 &&arg, Params &&...params)
    {
        ret =
            fun(std::forward<Arg1>(arg), std::forward<Params>(params) ...);
    }
};

template <  int size, typename Tuple,
            typename Fun, typename Arg1, typename ... Params>
struct Wrap1<size, void, Tuple, Fun, Arg1, Params ...>
{
    typedef typename std::tuple_element<size - 1, Tuple>::type ElType;

    inline Wrap1(Tuple &&tuple, Fun fun, Arg1 &&arg, Params &&...params)
    {
        Wrap1<size - 1, void, Tuple, Fun, Arg1, ElType, Params ...>
        (
            std::forward<Tuple>(tuple),
            fun,
            std::forward<Arg1>(arg),
            std::forward<ElType>(std::get<size - 1>(tuple)),
            std::forward<Params>(params) ...
        );
    }
};

template <  typename Tuple,
            typename Fun, typename Arg1, typename ... Params>
struct Wrap1<0, void, Tuple, Fun, Arg1, Params ...>
{
    inline Wrap1(Tuple &&tuple, Fun fun, Arg1 &&arg, Params &&...params)
    {
        fun(std::forward<Arg1>(arg), std::forward<Params>(params) ...);
    }
};

// ======================================================================

template <  int size,
            typename Return, typename Tuple,
            typename Fun, typename Arg1, typename Arg2, typename ... Params>
struct Wrap2
{
    typedef typename std::tuple_element<size - 1, Tuple>::type ElType;

    inline Wrap2(Return &ret,
                Tuple &&tuple, Fun fun, Arg1 &&arg1, Arg2 &&arg2,
                                                    Params &&...params)
    {
        Wrap2<size - 1, Return, Tuple, Fun, Arg1, Arg2, ElType, Params ...>
        (
            ret,
            std::forward<Tuple>(tuple),
            fun,
            std::forward<Arg1>(arg1),
            std::forward<Arg2>(arg2),
            std::forward<ElType>(std::get<size - 1>(tuple)),
            std::forward<Params>(params) ...
        );
    }
};

template < typename Return, typename Tuple,
           typename Fun, typename Arg1, typename Arg2, typename ... Params>
struct Wrap2<0, Return, Tuple, Fun, Arg1, Arg2, Params ...>
{
    inline Wrap2(Return &ret,
                Tuple &&tuple, Fun fun, Arg1 &&arg1, Arg2 &&arg2,
                                                    Params &&...params)
    {
        ret =
            fun(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2),
                std::forward<Params>(params) ...);
    }
};

// ======================================================================

template <  int size,
            typename Tuple,
            typename Fun, typename Arg1, typename Arg2, typename ... Params>
struct Wrap2<size, void, Tuple, Fun, Arg1, Arg2, Params ...>
{
    typedef typename std::tuple_element<size - 1, Tuple>::type ElType;

    inline Wrap2(
                Tuple &&tuple, Fun fun, Arg1 &&arg1, Arg2 &&arg2,
                                                    Params &&...params)
    {
        Wrap2<size - 1, void, Tuple, Fun, Arg1, Arg2, ElType, Params ...>
        (
            std::forward<Tuple>(tuple),
            fun,
            std::forward<Arg1>(arg1),
            std::forward<Arg2>(arg2),
            std::forward<ElType>(std::get<size - 1>(tuple)),
            std::forward<Params>(params) ...
        );
    }
};

template <
            typename Tuple,
            typename Fun, typename Arg1, typename Arg2, typename ... Params>
struct Wrap2<0, void, Tuple, Fun, Arg1, Arg2, Params ...>
{
    inline Wrap2(
                Tuple &&tuple, Fun fun, Arg1 &&arg1, Arg2 &&arg2,
                                                    Params &&...params)
    {
        fun(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2),
            std::forward<Params>(params) ...);
    }
};

template <typename P>
struct RetType;

template <typename Ret, typename ... Par>
struct RetType<Ret (*)(Par ...)>
{
    typedef Ret type;
};

} // IUO

template <int unary, typename Return, typename Fun, typename ... Params>
class Wrap
{
    Fun d_fun;
    std::tuple<Params ...> d_tuple;

    public:
        Wrap(Fun fun, Params &&...params)
        :
            d_fun(fun),
            d_tuple(std::forward<Params>(params) ...)
        {}

        template <typename Arg1>
        Return operator()(Arg1 &&arg1)
        {
            Return ret;
            IUO::Wrap1<
                std::tuple_size<std::tuple<Params ...>>::value,
                Return &,
                std::tuple<Params ...>,
                Fun,
                Arg1
                >
                (ret, d_tuple, d_fun, arg1);
            return ret;
        }
};


template <int unary, typename Fun, typename ... Params>
class Wrap<unary, void, Fun, Params ...>
{
    Fun d_fun;
    std::tuple<Params ...> d_tuple;

    public:
        Wrap(Fun fun, Params &&...params)
        :
            d_fun(fun),
            d_tuple(std::forward<Params>(params) ...)
        {}

        template <typename Arg1>
        void operator()(Arg1 &&arg1)
        {
            IUO::Wrap1<
                std::tuple_size<std::tuple<Params ...>>::value,
                void,
                std::tuple<Params ...>,
                Fun,
                Arg1
                >
                (d_tuple, d_fun, arg1);
        }
};


// ====================================================================

template <typename Return, typename Fun, typename ... Params>
class Wrap<2, Return, Fun, Params ...>
{
    Fun d_fun;
    std::tuple<Params ...> d_tuple;

    public:
        Wrap(Fun fun, Params &&...params)
        :
            d_fun(fun),
            d_tuple(std::forward<Params>(params) ...)
        {}

        template <typename Arg1, typename Arg2>
        Return operator()(Arg1 &&arg1, Arg2 &&arg2)
        {
            Return ret;
            IUO::Wrap2<
                std::tuple_size<std::tuple<Params ...>>::value,
                Return &,
                std::tuple<Params ...>,
                Fun,
                Arg1,
                Arg2
                >
                (ret, d_tuple, d_fun, arg1, arg2);
            return ret;
        }
};


template <typename Fun, typename ... Params>
class Wrap<2, void, Fun, Params ...>
{
    Fun d_fun;
    std::tuple<Params ...> d_tuple;

    public:
        Wrap(Fun fun, Params &&...params)
        :
            d_fun(fun),
            d_tuple(std::forward<Params>(params) ...)
        {}

        template <typename Arg1>
        void operator()(Arg1 &&arg1)
        {
            IUO::Wrap1<
                std::tuple_size<std::tuple<Params ...>>::value,
                void,
                std::tuple<Params ...>,
                Fun,
                Arg1
                >
                (d_tuple, d_fun, arg1);
        }
};


// ============================================================

struct Wrapper
{
    template <typename Func, typename ... Param>
    static Wrap<1,
                typename IUO::RetType<Func>::type /*Return*/,
                Func, Param ...>
        unary(Func fun, Param &&...param)
        {
            Wrap<1,
                typename IUO::RetType<Func>::type /*Return*/,
                        Func, Param ...>
                wrap(fun, std::forward<Param>(param) ... );
            return wrap;
        }

    template <typename Func, typename ... Param>
    static Wrap<2,
                typename IUO::RetType<Func>::type /*Return*/,
                Func, Param ...>
        binary(Func fun, Param &&...param)
        {
            Wrap<2,
                typename IUO::RetType<Func>::type /*Return*/,
                Func, Param ...>
                wrap(fun, std::forward<Param>(param) ... );
            return wrap;
        }

};

} // FBB

using namespace std;
using namespace FBB;

class Strings
{
    vector<string> d_vs;

    public:
        Strings()
        :
            d_vs({"one", "two", "", "three"})
        {}

        void display(ostream &out) const
        {
            size_t nr = 1;
            find_if(d_vs.begin(), d_vs.end(),
                Wrapper::unary(untilEmpty, nr, out));
        }

        void display() const
        {
            for_each(d_vs.begin(), d_vs.end(),
                Wrapper::unary(toCout));
        }

        void show(ostream &out) const
        {
            size_t nr = 1;
            for_each(d_vs.begin(), d_vs.end(),
                Wrapper::unary(all, nr, out));
        }

        void accu(ostream &out) const
        {
            size_t nr = 1;
            equal(d_vs.begin(), d_vs.end(), d_vs.rbegin(),
                Wrapper::binary(cmpfun2, nr, out));
        }

    private:
        static bool cmpfun2(string const &str1, string const &str2,
                        size_t &nr, ostream &out)
        {
            out << nr++ << " " << str1 << " and " << str2 << '\n';
            return true;           // don't stop
        }

        static void toCout(string const &str)
        {
            cout << "toCout: " << str << '\n';
        }

        static bool untilEmpty(string const &str, size_t &nr, ostream &out)
        {
            if (str.empty())
                return true;        // stop

            out << nr++ << " " << str << '\n';
            return false;           // don't stop
        }
        static void all(string const &str, size_t &nr, ostream &out)
        {
            out << nr++ << " " << str << '\n';
        }
};

int main()
{
    Strings s;

    s.display(cout);
    cout << "========\n";
    s.display();
    cout << "========\n";
    s.show(cout);
    cout << "========\n";
    s.accu(cout);
}
