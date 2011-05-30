template <typename ...Types>
struct Remove;

template<typename Rm>
struct Remove<TypeList<Rm>>                 // empty list
{
    typedef TypeList<> Removed;
};

template<typename Rm, typename ...Tail>     // remove Rm fm the head,
struct Remove<TypeList<Rm, Rm, Tail...>>
{
    typedef typename Remove<TypeList<Rm, Tail...>>::Removed Removed;
};

                                            // keep First, rm Rm from Tail
                                            // concatenate the two
template<typename Rm, typename First, typename ...Tail>
struct Remove<TypeList<Rm, First, Tail...>>
{
    typedef TypeList<First, 
        typename Remove<TypeList<Rm, Tail...>>::Removed
                    > Removed;
};


    
