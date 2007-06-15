#include "typetrait.h"

template <typename Type, typename Context, typename ReturnType = void>
class FnWrap1c
{
    ReturnType (*d_fun)(Type, Context);
    Context d_context;

    public:
        typedef typename TypeTrait<Type>::Plain         argument_type;
        typedef typename TypeTrait<ReturnType>::Plain   result_type;

        FnWrap1c(ReturnType fun(Type, Context), Context context);
        ReturnType operator()(Type param) const;
};

template <typename Type, typename Context, typename ReturnType>
FnWrap1c<Type, Context, ReturnType>::FnWrap1c(
                ReturnType fun(Type, Context), Context context)
:
    d_fun(fun),
    d_context(context)
{}

template <typename Type, typename Context, typename ReturnType>
inline ReturnType FnWrap1c<Type, Context, ReturnType>::operator()(Type param)
                                                                  const
{
    return (*d_fun)(param, d_context);
}
