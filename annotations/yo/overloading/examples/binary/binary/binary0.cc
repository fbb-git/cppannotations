#include "binary.ih"

Binary::Binary()
:
    d_ip(new int),
    d_nr(s_copy.size() + 100),
    d_copy(s_copy[d_nr]++)
{
    cout << "default constructor of object " << d_nr << ':' << d_copy << '\n';
}
