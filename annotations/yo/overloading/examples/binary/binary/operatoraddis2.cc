#include "binary.ih"

Binary &&Binary::operator+=(Binary const &rhs) &&
{
    cout << "&&" << d_nr << ':' << d_copy << " += " <<
                    rhs.d_nr << ':' << rhs.d_copy << '\n';

    add(rhs);
    return std::move(*this);
}
