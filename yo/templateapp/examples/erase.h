#include "typelist.h"

template <typename TypeList, typename EraseType>
struct Erase;

template <typename EraseType>
struct Erase<NullType, EraseType>
{
    typedef NullType Result;
};

template <typename EraseType, typename Tail>
struct Erase<TypeList<EraseType, Tail>, EraseType>
{
    typedef Tail Result;
};

template <typename Head, typename Tail, typename EraseType>
struct Erase<TypeList<Head, Tail>, EraseType>
{
    typedef TypeList<Head, 
                    typename Erase<Tail, EraseType>::Result> Result;
};

template <typename TypeList, typename EraseType>
struct EraseAll: public Erase<TypeList, EraseType>
{};

template <typename EraseType, typename Tail>
struct EraseAll<TypeList<EraseType, Tail>, EraseType> 
{
    typedef typename EraseAll<Tail, EraseType>::Result Result;
};

//ERASEDUP
    template <typename TypeList>
    struct EraseDuplicates;
    
    template <>
    struct EraseDuplicates<NullType>
    {
        typedef NullType  Result;
    };
    
    template <typename Head, typename Tail>
    class EraseDuplicates<TypeList<Head, Tail> >
    {
        typedef typename EraseDuplicates<Tail>::Result UniqueTail;
        typedef typename Erase<UniqueTail, Head>::Result  NewTail;
    
        public:
            typedef TypeList<Head, NewTail>  Result;
    };
//=
