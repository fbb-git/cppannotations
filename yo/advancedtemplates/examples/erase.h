#ifndef INCLUDED_ERASE_H_
#define INCLUDED_ERASE_H_

#include "append.h"

//ERASE
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
    template <typename Head, typename EraseType, typename ... Tail>
    struct Erase<EraseType, TypeList<Head, Tail ...>>
    {
        typedef typename Prefix<
                    Head, 
                    typename Erase<EraseType, TypeList<Tail ...>>::List
                >::List List;
    };
//=

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

//ERASEIDX
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


////ERASEALL
//    template <typename TypeList, typename EraseType>
//    struct EraseAll: public Erase<TypeList, EraseType>
//    {};
////=
//
////ALLTYPES
//    template <typename EraseType, typename Tail>
//    struct EraseAll<TypeList<EraseType, Tail>, EraseType>
//    {
//        typedef typename EraseAll<Tail, EraseType>::Result Result;
//    };
////=
//
////ERASEDUP
//    template <typename TypeList>
//    struct EraseDuplicates;
//
//    template <>
//    struct EraseDuplicates<NullType>
//    {
//        typedef NullType  Result;
//    };
//
//    template <typename Head, typename Tail>
//    class EraseDuplicates<TypeList<Head, Tail> >
//    {
//        typedef typename EraseDuplicates<Tail>::Result UniqueTail;
//        typedef typename Erase<UniqueTail, Head>::Result  NewTail;
//
//        public:
//            typedef TypeList<Head, NewTail>  Result;
//    };
////=

#endif
