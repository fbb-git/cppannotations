#include "typelist.h"
#include "at.h"

namespace 
{
template <int idx, typename Base>
struct Unit: public Base
{
    Unit(Base const &base)
    :
        Base(base)
    {}
    Unit()
    {}
};

template <typename Atomic, template <typename> class UnitTTP, int idx>
class GenScatter
: 
    virtual public Unit<idx, UnitTTP<Atomic> >
{
    public:
        typedef Unit<idx, UnitTTP<Atomic> >   LeftBase;

        typedef LeftBase        Base;       // new

        typedef TYPELIST_1(Atomic)  TList;

        typedef TYPELIST_1(LeftBase)    BaseList;

};



template <
          typename Head, typename Tail, template <typename> class UnitTTP,
          int idx>
class GenScatter<TypeList<Head, Tail>, UnitTTP, idx>
: 
    public GenScatter<Head, UnitTTP, idx>,
    public GenScatter<Tail, UnitTTP, idx + 1>
{
    public:
        typedef GenScatter<Head, UnitTTP, idx > LeftBase;
        typedef GenScatter<Tail, UnitTTP, idx + 1> RightBase;
        typedef TypeList<Head, Tail>    TList;

        typedef Unit<idx, UnitTTP<Head> >  Base;   // new

        typedef TypeList<Base, typename RightBase::BaseList> BaseList;
};


template <template <typename> class UnitTTP, int idx>
class GenScatter<NullType, UnitTTP, idx>
{
    public:
        typedef NullType    TList;
        typedef NullType BaseList;
};

} // namespace

template <typename Atomic, template <typename> class UnitTTP>
class GenScat: public GenScatter<Atomic, UnitTTP, 0>
{};


template <int idx, typename GenScatterType>
    typename AtIndex<typename GenScatterType::BaseList, idx>::Result
 &base(GenScatterType &obj)
{
    return obj;
}

template <int indx, typename Derived>
struct BaseClass
{
    typedef typename AtIndex<typename Derived::BaseList, indx>::Result Init;
};


