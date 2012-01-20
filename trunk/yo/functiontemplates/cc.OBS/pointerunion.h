    union PointerUnion
    {
        int (*fp)(int *, size_t);
        void *vp;
    };
