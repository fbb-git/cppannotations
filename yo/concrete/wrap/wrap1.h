    template <typename Type, typename Context, typename ReturnType = void>
    class Wrap1
    {
        Context &d_context;
        union
        {
            ReturnType (*d_ref)(Type &, Context &);
            ReturnType (*d_constref)(Type const &, Context &);
            ReturnType (*d_ptr)(Type *, Context &);
            ReturnType (*d_constptr)(Type const *, Context &);
        };
        public:
            typedef Type        argument_type;
            typedef ReturnType  result_type;
                                                // reference
            Wrap1(ReturnType (*fun)(Type &, Context &), Context &context)
            :
                d_context(context),
                d_ref(fun)
            {}
            ReturnType operator()(Type &param) const
            {
                return (*d_ref)(param, d_context);
            }
                                                // const reference
            Wrap1(ReturnType (*fun)(Type const &, Context &),
                                                        Context &context)
            :
                d_context(context),
                d_constref(fun)
            {}
            ReturnType operator()(Type const &param) const
            {
                return (*d_constref)(param, d_context);
            }
                                                // pointer
            Wrap1(ReturnType (*fun)(Type *, Context &), Context &context)
            :
                d_context(context),
                d_ptr(fun)
            {}
            ReturnType operator()(Type *param) const
            {
                return (*d_ptr)(param, d_context);
            }
                                                // const pointer
            Wrap1(ReturnType (*fun)(Type const *, Context &),
                                                        Context &context)
            :
                d_context(context),
                d_constptr(fun)
            {}
            ReturnType operator()(Type const *param) const
            {
                return (*d_constptr)(param, d_context);
            }
    };
