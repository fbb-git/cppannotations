    union PointerUnion
    {
        int (*fp)(int const &, int const &);
        void *vp;
    };
