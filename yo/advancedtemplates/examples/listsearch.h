#include "typelist.h"

//LISTSEARCH
    template <typename ... Types>
    struct ListSearch
    {
        ListSearch(ListSearch const &) = delete;
    };
//=

//EMPTY
    template <typename SearchType>
    struct ListSearch<SearchType, TypeList<>>
    {
        ListSearch(ListSearch const &) = delete;
        enum { index = -1 };
    };
//=

//TAIL
    template <typename SearchType, typename ... Tail>
    struct ListSearch<SearchType, TypeList<SearchType, Tail ...>>
    {
        ListSearch(ListSearch const &) = delete;
        enum { index = 0 };
    };
//=

//FULL
    template <typename SearchType, typename Head, typename ... Tail>
    struct ListSearch<SearchType, TypeList<Head, Tail ...> >
    {
        ListSearch(ListSearch const &) = delete;
        enum {tmp = ListSearch<SearchType, TypeList<Tail ...>>::index};
        enum {index = tmp == -1 ? -1 : 1 + tmp};
    };
//=

