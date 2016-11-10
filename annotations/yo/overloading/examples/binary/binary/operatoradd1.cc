#include "binary.ih"

Binary operator+(Binary const &lhs, Binary const &rhs)
{
    cout << lhs.d_nr <<  ':' << lhs.d_copy << " + " <<
            rhs.d_nr << ':' << rhs.d_copy << '\n';

    Binary tmp(lhs);
    tmp.add(rhs);
    return tmp;
}
