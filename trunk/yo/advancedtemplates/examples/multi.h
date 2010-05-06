#include <vector>

template <typename ... Types>
struct TypeList
{
    TypeList(TypeList const &) = delete;
    enum { size = sizeof ... (Types) };
};

//VECTOR
    template <class Type>
    struct Vector: public std::vector<Type>
    {
        Vector(std::initializer_list<Type> iniValues)
        :
            std::vector<Type>(iniValues)
        {}
    };
//=

//UWRAP
    template <size_t nr, typename Type>
    struct UWrap: public Type
    {
        UWrap(Type const &type)
        :
            Type(type)
        {}
    };
//=

//MULTIBASE
    template <size_t nr, typename ... PolicyTypes>
    struct MultiBase;
//=

//MULTIBASEREC
    template <size_t nr, typename PolicyT1, typename ... PolicyTypes>
    struct MultiBase<nr, PolicyT1, PolicyTypes ...> :
                                public UWrap<nr, PolicyT1>,
                                public MultiBase<nr + 1, PolicyTypes ...>
    {
        typedef PolicyT1 Type;
        typedef MultiBase<nr + 1, typename PolicyTypes ...> Base;

        MultiBase(PolicyT1 && policyt1, PolicyTypes &&... policytypes)
        :
            UWrap<nr, PolicyT1>(std::forward<PolicyT1>(policyt1)),
            MultiBase<nr + 1, PolicyTypes ...>(
                              std::forward<PolicyTypes>(policytypes) ...)
        {}
    };
//=

//MULTIBASEDONE
    template <size_t nr>
    struct MultiBase<nr>
    {};
//=

//MULTI
    template <template <typename> class Policy, typename ... Types>
    struct Multi: public MultiBase<0, Policy<Types> ...>
    {
        typedef TypeList<Types ...> PlainTypes;
        typedef MultiBase<0, Policy<Types> ...> Base;

        enum { size = PlainTypes::size };

        Multi(Policy<Types> &&... types)
        :
            MultiBase<0, Policy<Types> ...>(
                            std::forward<Policy<Types>>(types) ...)
        {}
    };
//=

template <typename TP>
struct st
{
    static_assert(sizeof(TP) == 0, "");
};

//TYPEAT
    template <size_t index, typename Multi>
    class typeAt
    {
        template <size_t idx, typename MultiBase>
        struct PolType;

        template <size_t idx,
                  size_t nr, typename PolicyT1, typename ... PolicyTypes>
        struct PolType<idx, MultiBase<nr, PolicyT1, PolicyTypes ...>>
        {
            typedef typename PolType<
                idx - 1, MultiBase<nr + 1, PolicyTypes ...>>::Type Type;
        };

        template <size_t nr, typename PolicyT1, typename ... PolicyTypes>
        struct PolType<0, MultiBase<nr, PolicyT1, PolicyTypes ...>>
        {
            typedef PolicyT1 Type;
        };
    public:
        typeAt(typeAt const &) = delete;
        typedef typename PolType<index, typename Multi::Base>::Type Type;
    };
//=

//GET
    template <size_t idx, typename Multi>
    inline typename typeAt<idx, Multi>::Type &get(Multi &multi)
    {
        return static_cast<
                UWrap<idx, typename typeAt<idx, Multi>::Type> &>(multi);
    }
//=

//PLAINAT
    template <size_t index, typename Multi>
    class plainTypeAt
    {
        template <size_t idx, typename List>
        struct At;

        template <size_t idx, typename Head, typename ... Tail>
        struct At<idx, TypeList<Head, Tail...>>
        {
            typedef typename At<idx - 1, TypeList<Tail ...>>::Type Type;
        };

        template <typename Head, typename ... Tail>
        struct At<0, TypeList<Head, Tail...>>
        {
            typedef Head Type;
        };

    public:
        plainTypeAt(plainTypeAt const &) = delete;
        typedef typename At<index, typename Multi::PlainTypes>::Type Type;
    };
//=
