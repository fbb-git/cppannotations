#include "tabber.ih"

void Tabber::outSpaces()
{
    if (d_nSpaces != 0)
        d_out << setw(d_nSpaces) << ' ';
    d_nSpaces = 0;
}
