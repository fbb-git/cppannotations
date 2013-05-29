    #include <functional>

    template <typename _Tp>
    struct bit_not: public std::unary_function<_Tp, _Tp>
    {
        _Tp operator()(_Tp const &__x) const
        {
            return ~__x;
        }
    };
