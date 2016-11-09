#include "binary.ih"

Binary::Binary(Binary &&tmp)
:
    d_ip(tmp.d_ip),
    d_nr(tmp.d_nr),
    d_copy(s_copy[d_nr]++)
{
    tmp.d_ip = 0;
    cout << d_nr << ':' << d_copy << "{&&" << 
                            tmp.d_nr << ':' << tmp.d_copy << "}\n";
}

