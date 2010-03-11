#ifndef INCLUDED_ERASE_H_
#define INCLUDED_ERASE_H_

#include "append.h"

//ERASEIDX
    template <size_t idx, typename TypeList>
    struct EraseIdx;
//=

//ERASEIDXEMPTY
    template <size_t idx>
    struct EraseIdx<idx, TypeList<>>
    {
        typedef TypeList<> List;
    };
//=

//ERASEIDXZERO
    template <typename EraseType, typename ... Tail>
    struct EraseIdx<0, TypeList<EraseType, Tail ...>>
    {
        typedef TypeList<Tail ...> List;
    };
//=

//ERASEIDXNEXT
    template <size_t idx, typename Head, typename ... Tail>
    struct EraseIdx<idx, TypeList<Head, Tail ...>>
    {
        typedef typename Prefix<
                    Head,
                    typename EraseIdx<idx - 1, TypeList<Tail ...>>::List
                >::List List;
    };
//=

//ERASEPLAIN
    template <typename EraseType, typename TypeList>
    struct Erase;
//=

//ERASEEMPTY
    template <typename EraseType>
    struct Erase<EraseType, TypeList<>>
    {
        typedef TypeList<> List;
    };
//=

//ERASEHEAD
    template <typename EraseType, typename ... Tail>
    struct Erase<EraseType, TypeList<EraseType, Tail ...>>
    {
        typedef TypeList<Tail ...> List;
    };
//=

//ERASENEXT
    template <typename EraseType, typename Head, typename ... Tail>
    struct Erase<EraseType, TypeList<Head, Tail ...>>
    {
        typedef typename
            Prefix<Head,
                typename Erase<EraseType, TypeList<Tail ...>>::List
            >::List List;
    };
//=

//ERASEALL
    template <typename EraseType, typename TypeList>
    struct EraseAll: public Erase<EraseType, TypeList>
    {};
//=

//ERASEALLTYPES
    template <typename EraseType, typename ... Tail>
    struct EraseAll<EraseType, TypeList<EraseType, Tail ...>>
    {
        typedef typename EraseAll<EraseType, TypeList<Tail ...>>::List List;
    };
//=

//ERASEALLNEXT
    template <typename EraseType, typename Head, typename ... Tail>
    struct EraseAll<EraseType, TypeList<Head, Tail ...>>
    {
        typedef typename Prefix<
            Head,
            typename EraseAll<EraseType, TypeList<Tail ...>>::List
        >::List List;
    };
//=

//ERASEDUP
    template <typename TypeList>
    struct EraseDup;
//=
//ERASEDUPEMPTY
    template <>
    struct EraseDup<TypeList<>>
    {
        typedef TypeList<> List;
    };
//=
//ERASEDUPHEAD
    template <typename Head, typename ... Tail>
    struct EraseDup<TypeList<Head, Tail ...>>
    {
        typedef typename EraseDup<TypeList<Tail ...>>::List UniqueTail;
        typedef typename Erase<Head, UniqueTail>::List NewTail;

        typedef typename Prefix<Head, NewTail>::List List;
    };
//=

#endif
