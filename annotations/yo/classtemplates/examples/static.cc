    template <typename Type>
    class TheClass
    {
        static int s_objectCounter;         // declaration

    };

    template <typename Type>                // definition
    int TheClass<Type>::s_objectCounter = 0;
