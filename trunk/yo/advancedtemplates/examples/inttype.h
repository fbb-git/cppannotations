#ifndef INCLUDED_INTTYPE_H_
#define INCLUDED_INTTYPE_H_

template <int nr>
struct IntType
{
    enum { value = nr } ;
};

#endif
