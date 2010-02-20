#ifndef INCLUDED_UNIQ_H_
#define INCLUDED_UNIQ_H_

#include "typelist.h"
#include "append.h"
#include "remove.h"

template <typename ... Params>
struct Uniq;

template <>
struct Uniq<TypeList<>>
{
    typedef TypeList<> List;
};

template <typename Head, typename ... Tail>
struct Uniq<TypeList<Head, Tail ...>>
{
    typedef typename Remove<Head, TypeList<Tail ...>>::List RmList;
    typedef typename Uniq<RmList>::List UTail;

    typedef typename Prefix<Head, UTail>::TList List;
};

#endif
