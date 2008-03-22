#ifndef INCLUDED_TYPEAT_H_
#define INCLUDED_TYPEAT_H_

#include "typelist.h"

//TYPEAT
    template <int index, typename Typelist>
    struct TypeAt;
//=

//NULLTYPE
    template <int index>
    struct TypeAt<index, NullType>
    {
        typedef NullType Type;
    };
//=

//ZERO
    template <typename Head, typename Tail>
    struct TypeAt<0, TypeList<Head, Tail> >
    {
        typedef Head Type;
    };
//=

//TYPELIST
    template <int index, typename Head, typename Tail>
    struct TypeAt<index, TypeList<Head, Tail> >
    {
        typedef typename TypeAt<index - 1, Tail>::Type Type;
    };
//=

#endif
