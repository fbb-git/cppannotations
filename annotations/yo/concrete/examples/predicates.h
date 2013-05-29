//UNARYPRED
    template<typename Type, typename F_PTR = int(*)(int)>
    class PredicateFunction1
    {
        F_PTR d_fun;
        public:
            typedef Type argument_type;

            PredicateFunction1(F_PTR const &ptr)
            :
                d_fun(ptr)
            {}

            bool operator()(Type const &t) const
            {
                return d_fun(t);
            }
    };
//=
//BINPRED
    template<typename Type1, typename Type2,
             typename F_PTR = int(*)(Type1 const &t1, Type2 const &t2)>
    class PredicateFunction2
    {
        F_PTR d_fun;
        public:
            typedef Type1   first_argument_type;
            typedef Type2   second_argument_type;
            typedef bool    result_type;

            PredicateFunction2(F_PTR const &ptr)
            :
                d_fun(ptr)
            {}

            bool operator()(Type1 const &t1, Type2 const &t2) const
            {
                return d_fun(t1, t2);
            }
    };
//=
//PREDOBJ1
    template <class Class, typename Type>
    class PredicateObject1
    {
        Class &d_cl;
        bool (Class::*d_member)(Type const &);

        public:
            typedef Type argument_type;

            PredicateObject1(Class &cl, bool (Class::*member)(Type const &) =
                                       &Class::operator())
            :
                d_cl(cl),
                d_member(member)
            {}
            PredicateObject1(Class *cl, bool (Class::*member)(Type const &) =
                                    &Class::operator())
            :
                d_cl(*cl),
                d_member(member)
            {}
            bool operator()(Type const &t) const
            {
                return (d_cl.*d_member)(t);
            }
            operator Class() const
            {
                return d_cl;
            }
    };
//=
//PREDOBJ2
    template <class Class, typename Type1, typename Type2 = Type1>
    class PredicateObject2
    {
        Class &d_cl;
        bool (Class::*d_member)(Type1 const &, Type2 const &);
        public:
            typedef Type1   first_argument_type;
            typedef Type2   second_argument_type;
            typedef bool    result_type;

            PredicateObject2(Class &cl,
                    bool (Class::*member)(Type1 const &, Type2 const &) =
                                       &Class::operator())
            :
                d_cl(cl),
                d_member(member)
            {}
            PredicateObject2(Class *cl,
                    bool (Class::*member)(Type1 const &, Type2 const &) =
                                       &Class::operator())
            :
                d_cl(*cl),
                d_member(member)
            {}
            bool operator()(Type1 const &t1, Type2 const &t2) const
            {
                return (d_cl.*d_member)(t1, t2);
            }
            operator Class() const
            {
                return d_cl;
            }
    };
//=
