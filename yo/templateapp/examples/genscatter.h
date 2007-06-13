#include "typelist.h"
#include "typeat.h"

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
    template <typename Type, template <typename> class TemplateClass, int idx>
    class GenScatter
    : 
        virtual public Wrap<TemplateClass<Type>, idx>
    {
        typedef Wrap<TemplateClass<Type>, idx> Base;
    
        public:
            typedef TYPELIST_1(Base)    WrapList;
    };
//=

//GENCORE
    template <
        typename Head, typename Tail, 
        template <typename> class TemplateClass, int idx
    >
    class GenScatter<TypeList<Head, Tail>, TemplateClass, idx>
    : 
        virtual public Wrap<TemplateClass<Head>, idx>,
        public GenScatter<Tail, TemplateClass, idx + 1>
    {
        typedef typename GenScatter<Tail, TemplateClass, idx + 1>::WrapList  
                BaseWrapList;
        public:
            typedef TypeList<Wrap<TemplateClass<Head>, idx>, BaseWrapList> 
                    WrapList;
    };
//=

//GENNULL
    template <template <typename> class TemplateClass, int idx>
    class GenScatter<NullType, TemplateClass, idx>
    {
        public:
            typedef NullType WrapList;
    };
//=

} // namespace

//GENSCAT
    template <typename Type, template <typename> class TemplateClass>
    class GenScat: public GenScatter<Type, TemplateClass, 0>
    {};
//=


//BASECLASS
template <int idx, typename Derived>
struct BaseClass
{
    typedef typename TypeAt<idx, typename Derived::WrapList>::Type Type;
};
//=

template <int idx, typename GenScatterType>
typename BaseClass<idx, GenScatterType>::Type &base(GenScatterType &obj)
{
    return obj;
}

