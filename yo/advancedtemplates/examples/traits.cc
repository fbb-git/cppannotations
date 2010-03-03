#include <stdint.h>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

template <int x>
struct IntType
{
    enum
    {
        value = x
    };
};


template <typename T>
class TypeTrait
{
    template <typename U> struct Type
    {
        enum { isPointer = false };
        enum { isConst   = false };

        typedef U Plain;
    };

    template <typename U> struct Type<U const>
    {
        enum { isPointer = false };
        enum { isConst   = true };

        typedef U Plain;
    };

    typedef char small;
    struct Big {char big[2];};

    template <typename T2>
    static small fun(...);

    template <typename T2>
    static Big   fun(void (T2::*)());

//    template <typename T2>
//    static IntType<false> fun(...);
//
//    template <typename T2>
//    static IntType<true>  fun(void (T2::*)());

    public:
        enum { isConst     = Type<T>::isConst };
        enum { isClass     = sizeof(fun<T>(0)) == sizeof(Big) };
//        enum { isClass     = fun<T>(0)::value;
};

int main()
{
    string s;
    cout << TypeTrait<string>::isClass << '\n';
    cout << TypeTrait<int>::isClass << '\n';
}
