#ifndef INCLUDED_APPEND_H_
#define INCLUDED_APPEND_H_

#include "typelist.h"

//STRUCTS
    template <typename ...Types>
    struct Append;

    template <typename ...Types>
    struct Prefix;
//=

//ADDTYPE
    template <typename NewType, typename ...Types>
    struct Append<TypeList<Types...>, NewType>
    {
        typedef TypeList<Types..., NewType> List;
    };

    template <typename NewType, typename ...Types>
    struct Prefix<NewType, TypeList<Types...>>
    {
        typedef TypeList<NewType, Types...> List;
    };
//=

#endif
