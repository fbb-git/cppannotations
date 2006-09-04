    template <typename Type1, typename Type2,
              typename Context, typename ReturnType = void>
        class Wrap2
    {
        union
        {
            ReturnType (*d_ref)(Type1 &, Type2 &);
            ReturnType (*d_constref)(Type1 const &, Type2 const &);
            ReturnType (*d_ptrs)(Type1 *, Type2 *);
            ReturnType (*d_constptrs)(Type1 const *, Type2 const *);
        };
        Context &d_context;

        public:
            typedef Type1       first_argument_type;
            typedef Type2       second_argument_type;
            typedef ReturnType  result_type;

                                                        // references
            Wrap2(ReturnType (*fun)(Type1 &, Type2 &), Context &),
                  Context &context)
            :
                d_ref(fun),
                d_context(context)
            {}
            ReturnType operator()(Type1 &param1, Type2 &param2) const
            {
                return (*d_ref)(param1, param2, d_context);
            }

                                                        // const references
            Wrap2(ReturnType (*fun)(Type1 const &, Type2 const &), Context &),
                  Context &context)
            :
                d_constref(fun),
                d_context(context)
            {}
            ReturnType operator()(Type1 const &param1,
                                  Type2 const &param2) const
            {
                return (*d_constref)(param1, param2, d_context);
            }

                                                        // pointers
            Wrap2(ReturnType (*fun)(Type1 *, Type2 *), Context &),
                  Context &context)
            :
                d_ptrs(fun),
                d_context(context)
            {}
            ReturnType operator()(Type1 *param1, Type2 *param2) const
            {
                return (*d_ptrs)(param1, param2, d_context);
            }

                                                        // const pointers
            Wrap2(ReturnType (*fun)(Type1 const *, Type2 const *), Context &),
                  Context &context)
            :
                d_constptrs(fun),
                d_context(context)
            {}
            ReturnType operator()(Type1 const *param1,
                                  Type2 const *param2) const
            {
                return (*d_constptrs)(param1, param2, d_context);
            }
    };
