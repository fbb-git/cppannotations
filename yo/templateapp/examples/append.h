#ifndef _INCLUDED_APPEND_H_
#define _INCLUDED_APPEND_H_

#include "typelist.h"

//APPEND
    template <typename TypeList, typename NewType>
    struct Append;
//=

//NULLTYPE
    template <>
    struct Append<NullType, NullType>
    {
        typedef NullType TList;
    };
//=

//ADDNULL
    template <typename Head, typename Tail>
    struct Append<TypeList<Head, Tail>, NullType>
    {
        typedef TypeList<Head, Tail>  TList;
    };
//=

//NEWTYPE
    template <typename NewType>
    struct Append<NullType, NewType>
    {
        typedef TYPELIST_1(NewType) TList;
    };
//=

//TYPELIST
    template <typename Head, typename Tail, typename NewType>
    struct Append<TypeList<Head, Tail>, NewType>
    {
        typedef TypeList<Head, typename Append<Tail, NewType>::TList>
                TList;
    };
//=

#endif
