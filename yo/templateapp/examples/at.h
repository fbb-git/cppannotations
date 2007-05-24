#ifndef _INCLUDED_AT_H_
#define _INCLUDED_AT_H_

#include "typelist.h"

template <typename TList, int idx>
struct AtIndex;

template <typename Head, typename Tail>
struct AtIndex<TypeList<Head, Tail>, 0>
{
    typedef Head Result;
};

template <typename Head, typename Tail, int idx>
struct AtIndex<TypeList<Head, Tail>, idx>
{
    typedef typename AtIndex<Tail, idx - 1>::Result Result;
};

#endif
