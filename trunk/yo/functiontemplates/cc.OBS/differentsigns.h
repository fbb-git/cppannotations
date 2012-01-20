    template<typename T>
    bool differentSigns(T v1, T v2)
    {
        return
        (
            v1 < 0 && v2 >= 0
            ||
            v1 >= 0 && v2 < 0
        );
    }
