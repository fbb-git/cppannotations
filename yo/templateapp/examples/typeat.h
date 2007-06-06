#include "typelist.h"

template <int index, typename Typelist>
struct TypeAt;

template <int index>
struct TypeAt<index, NullType>
{
    typedef NullType result;
};

template <typename Head, typename Tail>
struct TypeAt<0, TypeList<Head, Tail> >
{
    typedef Head result;
};

template <int index, typename Head, typename Tail>
struct TypeAt<index, TypeList<Head, Tail> >
{
    typedef typename TypeAt<index - 1, Tail>::result result;
};
