#ifndef _INCLUDED_INTTYPE_H_
#define _INCLUDED_INTTYPE_H_

template <int nr>
struct IntType
{
    enum { value = nr } ;
};

#endif
