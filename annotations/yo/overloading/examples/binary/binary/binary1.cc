#include "binary.ih"

Binary::Binary(size_t nr)
:
    d_ip(new int),
    d_nr(nr),
    d_copy(s_copy[d_nr]++)
{
    cout << d_nr << ':' << d_copy << '{' << nr << "}\n";
}
