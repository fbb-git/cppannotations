#ifndef _INCLUDED_TYPELIST_H_
#define _INCLUDED_TYPELIST_H_

#include "nulltype.h"

template <typename First,  typename Second>
struct TypeList
{
    typedef First Head;
    typedef Second Tail;
};

#define TYPELIST_1(T1)          TypeList<T1, NullType >
#define TYPELIST_2(T1, T2)      TypeList<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3)  TypeList<T1, TYPELIST_2(T2, T3) >

#endif
