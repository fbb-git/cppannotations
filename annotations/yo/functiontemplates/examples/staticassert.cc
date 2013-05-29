    template <typename Type1, typename Type2>
    void rawswap(Type1 &type1, Type2 &type2)
    {
        static_assert(sizeof(Type1) != sizeof(Type2),
                        "rawswap: Type1 and Type2 must have equal sizes");
    }
