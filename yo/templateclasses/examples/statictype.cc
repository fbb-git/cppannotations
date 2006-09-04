    template <typename Type>
    class TheClass
    {
        static TheClass *s_objectPtr;
    };

    template <typename Type>
    TheClass<Type> *TheClass<Type>::s_objectPtr = 0;
