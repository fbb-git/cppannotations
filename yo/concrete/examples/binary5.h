    #ifndef INCLUDED_BINOPS_H_
    #define INCLUDED_BINOPS_H_

    #include <utility>

    template <typename Type>
    Type operator+(Type &&lhs, Type const &rhs)
    {
        return lhs += rhs;
    }

    template <typename Type>
    Type operator+(Type const &lhs, Type const &rhs)
    {
        Type tmp(lhs);
        return operator+(std::move(tmp), rhs);
    }
    
    #endif
