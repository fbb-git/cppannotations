#include "typelist.h"

//LISTSEARCH
    template <typename SearchType, typename TypeList> 
    struct ListSearch;
//=

//EMPTY
    template <typename SearchType>
    struct ListSearch<SearchType, NullType>
    {
        enum { index = -1 };
    };
//=

//TAIL    
    template <typename SearchType, typename Tail>
    struct ListSearch<SearchType, TypeList<SearchType, Tail> >
    {
        enum { index = 0 };
    };
//=
   
//TYPELIST 
    template <typename SearchType, typename Head, typename Tail>
    class ListSearch<SearchType, TypeList<Head, Tail> >
    {
        enum { tmp = ListSearch<SearchType, Tail>::index } ;
        public:
            enum { index = tmp == -1 ? -1 : 1 + tmp };
    };
//=
