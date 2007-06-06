#include "typelist.h"

template <typename SearchType, typename TypeList> 
struct ListSearch;

template <typename SearchType>
struct ListSearch<SearchType, NullType>
{
    enum { index = -1 };
};

template <typename SearchType, typename Tail>
struct ListSearch<SearchType, TypeList<SearchType, Tail> >
{
    enum { index = 0 };
};

template <typename SearchType, typename Head, typename Tail>
class ListSearch<SearchType, TypeList<Head, Tail> >
{
    enum { tmp = ListSearch<SearchType, Tail>::index } ;
    public:
        enum { index = tmp == -1 ? -1 : 1 + tmp };
};
