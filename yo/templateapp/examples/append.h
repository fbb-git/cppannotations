#include "typelist.h"

template <typename TypeList, typename NewType>
struct Append;

template <>
struct Append<NullType, NullType>
{
    typedef NullType Result;
};

template <typename TypeList>
struct Append<TypeList, NullType>
{
    typedef TypeList Result;
};

template <typename Head, typename Tail>
struct Append<TypeList<Head, Tail>, NullType>
{
    typedef TypeList<Head, Tail>  Result;
};

template <typename NewType>
struct Append<NullType, NewType>
{
    typedef TYPELIST_1(NewType) Result;
};

template <typename Head, typename Tail, typename NewType>
struct Append<TypeList<Head, Tail>, NewType>
{
    typedef TypeList<Head, 
                    typename Append<Tail, NewType>::Result>  Result;
};

