#include "binary.ih"

void Binary::swap(Binary &rhs)
{
    cout << d_nr <<  ':' << d_copy << " <-> " <<
            rhs.d_nr << ':' << rhs.d_copy << '\n';

    FBB::fswap(*this, rhs);
}
