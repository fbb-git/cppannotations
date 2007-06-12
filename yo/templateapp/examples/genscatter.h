#include "typelist.h"
#include "at.h"

namespace 
{
//WRAPPER
    template <typename Base, int idx>
    struct Wrap: public Base
    {
        Wrap(Base const &base)
        :
            Base(base)
        {}
        Wrap()
        {}
    };
//=

//GENMAIN
    template <typename Type, template <typename> class Policy, int idx>
    class GenScatter
    : 
        virtual public Wrap<Policy<Type>, idx>
    {
        typedef Wrap<Policy<Type>, idx> Base;
    
        public:
            typedef TYPELIST_1(Base)    WrapList;
    };
//=

//GENCORE
    template <
        typename Head, typename Tail, template <typename> class Policy, 
        int idx
    >
    class GenScatter<TypeList<Head, Tail>, Policy, idx>
    : 
        virtual public Wrap<Policy<Head>, idx>,
        public GenScatter<Tail, Policy, idx + 1>
    {
        typedef typename GenScatter<Tail, Policy, idx + 1>::WrapList  
                BaseWrapList;
        public:
            typedef TypeList<Wrap<Policy<Head>, idx>, BaseWrapList> WrapList;
    };
//=

//GENNULL
    template <template <typename> class Policy, int idx>
    class GenScatter<NullType, Policy, idx>
    {
        public:
            typedef NullType WrapList;
    };
//=

} // namespace

//GENSCAT
    template <typename Type, template <typename> class Policy>
    class GenScat: public GenScatter<Type, Policy, 0>
    {};
//=


//BASECLASS
template <int idx, typename Derived>
struct BaseClass
{
    typedef typename AtIndex<typename Derived::WrapList, idx>::Result Type;
};
//=

template <int idx, typename GenScatterType>
typename BaseClass<idx, GenScatterType>::Type &base(GenScatterType &obj)
{
    return obj;
}

