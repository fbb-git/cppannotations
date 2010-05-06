#ifndef INCLUDED_TYPEAT_H_
#define INCLUDED_TYPEAT_H_

#include "typelist.h"

//TYPEAT
    template <size_t index, typename Typelist>
    struct TypeAt;
//=

//INVALID
    template <size_t index>
    struct TypeAt<index, TypeList<>>
    {
        static_assert(index < 0, "TypeAt index out of bounds");
        typedef TypeAt Type;
    };
//=

//ZERO
    template <typename Head, typename ... Tail>
    struct TypeAt<0, TypeList<Head, Tail ...>>
    {
        typedef Head Type;
    };
//=

//TYPELIST
    template <size_t index, typename Head, typename ... Tail>
    struct TypeAt<index, TypeList<Head, Tail ...>>
    {
        typedef typename TypeAt<index - 1, TypeList<Tail ...>>::Type Type;
    };
//=

#endif
