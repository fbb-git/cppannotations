    template <typename Type, typename Context, typename ReturnType = void>
    class Wrap1
    {
        union
        {
            Context *d_context;
            Context const *d_contextconst;
        };
        union
        {
            ReturnType (*d_ref)(Type &, Context &);
            ReturnType (*d_refPtr)(Type &, Context *);
            ReturnType (*d_refCref)(Type &, Context const &);
            ReturnType (*d_refCptr)(Type &, Context const *);

            ReturnType (*d_ptr)(Type *, Context &);
            ReturnType (*d_ptr2)(Type *, Context *);
            ReturnType (*d_ptrCref)(Type *, Context const &);
            ReturnType (*d_ptrCptr)(Type *, Context const *);

            ReturnType (*d_crefRef)(Type const &, Context &);
            ReturnType (*d_crefPtr)(Type const &, Context *);
            ReturnType (*d_cref2)(Type const &, Context const &);
            ReturnType (*d_crefCptr)(Type const &, Context const *);

            ReturnType (*d_cptrRef)(Type const *, Context &);
            ReturnType (*d_cptrPtr)(Type const *, Context *);
            ReturnType (*d_cptrCref)(Type const *, Context const &);
            ReturnType (*d_cptr2)(Type const *, Context const *);
        };

        public:
            typedef Type        argument_type;
            typedef ReturnType  result_type;


            // Type may be &, *, const &, and const *
            // Context may be &, *, const &. and const *
            // This allows for 16 combinations which are now all implemented
            // below

            Wrap1(ReturnType (*fun)(Type &, Context &), Context &context);
            Wrap1(ReturnType (*fun)(Type &, Context const &),
                   Context const &context);
            Wrap1(ReturnType (*fun)(Type const &, Context &),
                   Context &context);
            Wrap1(ReturnType (*fun)(Type const &, Context const &),
                   Context const &context);
            Wrap1(ReturnType (*fun)(Type *, Context &),
                   Context &context);
            Wrap1(ReturnType (*fun)(Type *, Context const &),
                   Context const &context);
            Wrap1(ReturnType (*fun)(Type const *, Context &),
                   Context &context);
            Wrap1(ReturnType (*fun)(Type const *, Context const &),
                   Context const &context);

            // The following additional constructors are identical to the
            // constructors listed above, but they accept a pointer to a
            // context in various forms.

            Wrap1(ReturnType (*fun)(Type &, Context *), Context *context);
            Wrap1(ReturnType (*fun)(Type &, Context const *),
                   Context const *context);
            Wrap1(ReturnType (*fun)(Type const &, Context *),
                   Context *context);
            Wrap1(ReturnType (*fun)(Type const &, Context const *),
                   Context const *context);
            Wrap1(ReturnType (*fun)(Type *, Context *), Context *context);
            Wrap1(ReturnType (*fun)(Type *, Context const *),
                   Context const *context);
            Wrap1(ReturnType (*fun)(Type const *, Context *),
                   Context *context);
            Wrap1(ReturnType (*fun)(Type const *, Context const *),
                   Context const *context);

            ReturnType operator()(Type &param) const;
            ReturnType operator()(Type const &param) const;
            ReturnType operator()(Type *param) const;
            ReturnType operator()(Type const *param) const;
    };


template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type &, Context &), Context &context)
:
    d_context(&context),
    d_ref(fun)
{}
                                    // reference Wrap1::const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type &, Context const &),
                Context const &context)
:
    d_contextconst(&context),
    d_refCref(fun)
{}

                                    // const reference
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const &, Context &),
                Context &context)
:
    d_context(&context),
    d_crefRef(fun)
{}
                                    // const reference const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const &, Context const &),
                Context const &context)
:
    d_contextconst(&context),
    d_cref2(fun)
{}

                                    // pointer
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type *, Context &),
       Context &context)
:
    d_context(&context),
    d_ptr(fun)
{}
                                    // pointer const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type *, Context const &),
                Context const &context)
:
    d_contextconst(&context),
    d_ptrCref(fun)
{}

                                    // const pointer
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const *, Context &),
                Context &context)
:
    d_context(&context),
    d_cptrRef(fun)
{}
                                    // const pointer const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const *, Context const &),
                Context const &context)
:
    d_contextconst(&context),
    d_cptrCref(fun)
{}

                                    // reference
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type &, Context *), Context *context)
:
    d_context(context),
    d_refPtr(fun)
{}
                                    // reference const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type &, Context const *),
                Context const *context)
:
    d_contextconst(context),
    d_refCptr(fun)
{}

                                    // const reference
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const &, Context *), Context *context)
:
    d_context(context),
    d_crefPtr(fun)
{}
                                    // const reference const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const &, Context const *),
                Context const *context)
:
    d_contextconst(context),
    d_crefCptr(fun)
{}

                                    // pointer
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type *, Context *), Context *context)
:
    d_context(context),
    d_ptr2(fun)
{}
                                    // pointer const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type *, Context const *),
                Context const *context)
:
    d_contextconst(context),
    d_ptrCptr(fun)
{}
                                    // const pointer
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const *, Context *), Context *context)
:
    d_context(context),
    d_cptrPtr(fun)
{}
                                    // const pointer const
template <typename Type, typename Context, typename ReturnType>
Wrap1<Type, Context, ReturnType>::Wrap1(
                ReturnType (*fun)(Type const *, Context const *),
                Context const *context)
:
    d_contextconst(context),
    d_cptr2(fun)
{}

template <typename Type, typename Context, typename ReturnType>
ReturnType Wrap1<Type, Context, ReturnType>::operator()(Type &param) const
{
    return (*d_ref)(param, *d_context);
}

template <typename Type, typename Context, typename ReturnType>
ReturnType
        Wrap1<Type, Context, ReturnType>::operator()(Type const &param) const
{
    return (*d_crefRef)(param, *d_context);
}

template <typename Type, typename Context, typename ReturnType>
ReturnType Wrap1<Type, Context, ReturnType>::operator()(Type *param) const
{
    return (*d_ref)(*param, *d_context);
}

template <typename Type, typename Context, typename ReturnType>
ReturnType
        Wrap1<Type, Context, ReturnType>::operator()(Type const *param) const
{
    return (*d_crefRef)(*param, *d_context);
}
