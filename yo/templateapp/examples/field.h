#ifndef _INCLUDED_FIELD_H_
#define _INCLUDED_FIELD_H_

#include "at.h"
#include "typetype.h"
#include "inttype.h"

template <typename GenType, typename Result>
inline Result &fieldHelper(GenType &obj, TypeType<Result>, IntType<0>)
{
    typename GenType::LeftBase &subObj = obj;
    return subObj.d_value;
}

template <typename GenType, typename Result, int idx>
inline Result &fieldHelper(GenType &obj, TypeType<Result> tt, IntType<idx>)
{
    typename GenType::RightBase &subObj = obj;
    return FieldHelper(subObj, tt, IntType<idx - 1>());
}


template <typename GenScatterType>
struct FieldTraits
{
    template <int idx>
    struct At: public AtIndex<typename GenScatterType::TList, idx>
    {};
};


template <int idx, typename GenScatterType>
typename FieldTraits<GenScatterType>::template At<idx>::Result &
field(GenScatterType &obj)
{
    typedef typename FieldTraits<GenScatterType>::template At<idx>::Result 
            Result;

    return fieldHelper(obj, TypeType<Result>(), IntType<idx>());
}


#endif
