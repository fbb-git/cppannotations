#include "binary.ih"

Binary &Binary::operator=(Binary &&tmp)
{
    cout << d_nr << ':' << d_copy << " = &&" <<
                                        tmp.d_nr << ':' << tmp.d_copy << '\n';

    swap(tmp);
    return *this;
}
