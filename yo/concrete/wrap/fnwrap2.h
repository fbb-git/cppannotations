#include "typetrait"

template <typename Type1, typename Type2, typename ReturnType = void>
class FnWrap2
{
    ReturnType (*d_fun)(Type1, Type2);

    public:
        typedef typename TypeTrait<Type1>::Plain       first_argument_type;
        typedef typename TypeTrait<Type2>::Plain       second_argument_type;
        typedef typename TypeTrait<ReturnType>::Plain  result_type;

        FnWrap2(ReturnType fun(Type1, Type2));

        ReturnType operator()(Type1 p1, Type2 p2) const;
};

template <typename Type1, typename Type2, typename ReturnType>
inline FnWrap2<Type1, Type2, ReturnType>::FnWrap2(
                                            ReturnType (*fun)(Type1, Type2))
:
    d_fun(fun)
{}

template <typename Type1, typename Type2, typename ReturnType>
inline ReturnType FnWrap2<Type1, Type2, ReturnType>::operator()(
                                                    Type1 p1, Type2 p2) const
{
    return (*d_fun)(p1, p2);
}
