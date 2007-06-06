#include "typelist.h"

template <typename TypeList> 
struct ListSize;

template <>
struct ListSize<NullType>
{
    enum {  size = 0  };
};

template <typename Head, typename Tail>
struct ListSize<TypeList<Head, Tail> >
{
    enum {  size = 1 + ListSize<Tail>::size  };
};
