#include <iostream>
#include <utility>
#include <functional>

#include <vector>
#include <string>
#include <stack>
#include <thread>

using namespace std;

struct Forwarder
{
    string d_cl;

    Forwarder()
    :
        d_cl("1234567890")
    {}
    template<typename ...Args>
    string substr(Args&&... args)
    {
        return d_cl.substr(std::forward<Args>(args)...);
    }

////    void fwd(size_t (std::string::*ptr)())

////////////////////////////////////////////////////////////////
//    template <typename Ret, typename Member, typename Arg>
//    Ret fwd(Member member, Arg arg)
//
////        decltype (static_cast<Client &>(
////                    *static_cast<Client *>(0)
////                    ))
//
//
////        decltype(s_r)
//
//// Niet met .*       decltype ((d_cl.*member)(arg))
//
//    {
//        return (d_cl.*member)(arg);
//    }
////////////////////////////////////////////////////////////////

//    template <typename Ret, typename Member, typename ...Args>
//    Ret fwd(Member member, Args&&... args)
//    {
//        return (d_cl.*member)(std::forward<Args>(args)...);
//    }
};


struct X
{
    template <typename T>//, typename ... Args>
    struct result
    {
        typedef void type;
    };

    void operator()(int x)
    {
        cout << "int\n";
    }
    void operator()(double x)
    {
        cout << "double\n";
    }
    void operator()(double x, char const *)
    {
        cout << "double, string\n";
    }
    void operator()(ostream &out, double &x, char const *)
    {
        cout << "double, string\n";
    }
};

struct One
{
    One()
    {
        cout << "One()\n";
    }
    One(int)
    {
        cout << "One(int)\n";
    }
};

struct Two
{
    Two()
    {
        cout << "Two()\n";
    }
    Two(int)
    {
        cout << "Two(int)\n";
    }
};

template <typename Class, typename ... Args>
Class factory(Args&& ... args)
{
    return Class(std::forward<Args>(args) ...);
}

    void calledFunction(ostream &out)
    {
        out << "hello\n";
    }

    void calledFunction(int x)
    {
        ++x;
    }

    void calledFunction(int &x)
    {
        ++x;
    }

    template <typename ... Args>
    void caller(Args &&... args)
    {
        calledFunction(std::forward<Args>(args) ...);
    }

int main()
{
    int x = 0;
    caller(cout);
    caller(x);
    cout << x << endl;

//    int arg;
//    X x;
//    Forwarder forwarder;
//
//    string &&out = forwarder.substr(5, 2);
//
//    factory<One>();
//    Two two(factory<Two>(3));
//
//    factory<Two>(two);
//
//    cout << out << endl;

//    forwarder.function(x, 0);
//    forwarder.function(x, 0.0);
//
//    double d;
//    thread t(x, ref(cout), ref(d), "hi");
}
