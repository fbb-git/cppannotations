#include "binary.ih"

Binary operator+(Binary &&lhs, Binary const &rhs)
{
    cout << "&&" <<lhs.d_nr <<  ':' << lhs.d_copy << " + " << 
                   rhs.d_nr << ':' << rhs.d_copy << '\n';

    lhs.add(rhs);
    return std::move(lhs);
}
