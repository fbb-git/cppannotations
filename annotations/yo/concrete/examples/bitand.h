    #include <functional>

    template <typename _Tp>
    struct bitAnd: public std::binary_function<_Tp, _Tp, _Tp>
    {
        _Tp operator()(_Tp const &__x, _Tp const &__y) const
        {
            return __x & __y;
        }
    };
