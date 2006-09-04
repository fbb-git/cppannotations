    template
    <
        class T1,
        class T2,
        unsigned size1,
        unsigned size2
    >
        T1
        (
            *outerProduct
            (
                T2 const (&v1)[size1],
                T2 const (&v2)[size2]
            )
        )[size2];
