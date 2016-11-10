#include "binary.ih"

Binary &Binary::operator+=(Binary const &rhs) &
{
    cout << d_nr << ':' << d_copy << " += " << 
            rhs.d_nr << ':' << rhs.d_copy << '\n';

    Binary tmp(*this);
    tmp.add(rhs);     // this might throw
    swap(tmp);
    return *this;
}
