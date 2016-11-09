#include "binary.ih"

Binary::Binary(Binary const &other)
:
    d_ip(new int),
    d_nr(other.d_nr),
    d_copy(s_copy[d_nr]++)
{
    cout << d_nr << ':' << d_copy << '{' << 
                            other.d_nr << ':' << other.d_copy << "}\n";
}
