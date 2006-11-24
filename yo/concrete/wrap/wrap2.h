template <typename Type1, typename Type2,
          typename Context, typename ReturnType = void>
class Wrap2c
{
    union
    {
        Context *d_context;
        Context const *d_contextconst;
    };
    union
    {
        // from right to left the following is varied:
        //          references, pointers,
        //          const references, const pointers
        //  This makes for 4 variations on parameter 3,
        //      x 4 variations on parameter 2
        //      x 4 variations on parameter 1 = 64 variations

        // 3 sets of 16 variations not shown
        // set 4: 16  variations for Type1 const *:
            // 12 variations not shown.

        ReturnType (*d_cptr2ref)(Type1 const *, Type2 const *,
                                                        Context &);
        ReturnType (*d_cptr2ptr)(Type1 const *, Type2 const *,
                                                        Context *);
        ReturnType (*d_cptr2cref)(Type1 const *, Type2 const *,
                                                        Context const &);
        ReturnType (*d_cptr3)(Type1 const *, Type2 const *,
                                                        Context const *);
    };

    public:
        typedef Type1       first_argument_type;
        typedef Type2       second_argument_type;
        typedef ReturnType  result_type;

        // Type1 may be &, const &, * and const *
        // Type2 may be &, const &, * and const *
        // Context may be &, const &. * and const *
        // This allows for 64 combinations

    // Three blocks of 16 constructors not shown

    // Fourth block of 16 constructors: Type1 const *
        // Type 1: const *, Type2: &            - not shown
        // Type 1: const *, Type2: *            - not shown
        // Type 1: const *, Type2: const &      - not shown

        // Type 1: const *, Type2: const *
        Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *, Context &),
               Context &context);
        Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *, Context *),
               Context *context);
        Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *,
                                 Context const &), Context const &context);
        Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *,
                                 Context const *), Context const *context);

    // Member functions: 16, for ref, ptr, const ref, const ptr,
    //                       and two parameters per function
    // Type 1: ref          - not shown
    // Type 1: ptr          - not shown
    // Type 2: const ref    - not shown

    // Type 2: const ptr
        // ...
        ReturnType operator()(Type1 const *param1, Type2 const *param2) const;
};

// Fourth block of 16 constructors: Type1 const *

    // Type 1: const *, Type2: const *

    template<typename Type1, typename Type2, typename Context,
             typename ReturnType>
    Wrap2c<Type1, Type2, Context, ReturnType>::
    Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *, Context &),
           Context &context)
    :
        d_context(&context),
        d_cptr2ref(fun)
    {}

    template<typename Type1, typename Type2, typename Context,
             typename ReturnType>
    Wrap2c<Type1, Type2, Context, ReturnType>::
    Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *, Context *),
           Context *context)
    :
        d_context(context),
        d_cptr2ptr(fun)
    {}

    template<typename Type1, typename Type2, typename Context,
             typename ReturnType>
    Wrap2c<Type1, Type2, Context, ReturnType>::
    Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *, Context const &),
           Context const &context)
    :
        d_contextconst(&context),
        d_cptr2cref(fun)
    {}

    template<typename Type1, typename Type2, typename Context,
             typename ReturnType>
    Wrap2c<Type1, Type2, Context, ReturnType>::
    Wrap2c(ReturnType (*fun)(Type1 const *, Type2 const *, Context const *),
           Context const *context)
    :
        d_contextconst(context),
        d_cptr3(fun)
    {}

// Member functions: 16, for ref, ptr, const ref, const ptr,
//                       and two parameters per function
// ...

// Type 2: const ptr
    // ...

    template<typename Type1, typename Type2, typename Context,
             typename ReturnType>
    ReturnType Wrap2c<Type1, Type2, Context, ReturnType>::
    operator()(Type1 const *param1, Type2 const *param2) const
    {
        return (*d_cref2ref)(*param1, *param2, *d_context);
    }
