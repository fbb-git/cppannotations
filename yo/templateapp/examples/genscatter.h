#include "typelist.h"

template <typename Atomic, template <typename> class Unit>
class GenScatter
: 
    public Unit<Atomic>
{
    public:
        typedef Unit<Atomic>    LeftBase;
        typedef TYPELIST_1(Atomic)  TList;
};

template <typename Head, typename Tail, template <typename> class Unit>
class GenScatter<TypeList<Head, Tail>, Unit>
: 
    public GenScatter<Head, Unit>,
    public GenScatter<Tail, Unit>
{
    public:
        typedef GenScatter<Head, Unit> LeftBase;
        typedef GenScatter<Tail, Unit> RightBase;

        typedef TypeList<Head, Tail>    TList;
};


template <template <typename> class Unit>
class GenScatter<NullType, Unit>
{
    public:
        typedef NullType    TList;
};
