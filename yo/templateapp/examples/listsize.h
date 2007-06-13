#include "typelist.h"

//LISTSIZE
template <typename TypeList> 
struct ListSize;
//=

//NULLTYPE
    template <>
    struct ListSize<NullType>
    {
        enum {  size = 0  };
    };
//=

//TYPELIST
template <typename Head, typename Tail>
struct ListSize<TypeList<Head, Tail> >
{
    enum {  size = 1 + ListSize<Tail>::size  };
};
//=
