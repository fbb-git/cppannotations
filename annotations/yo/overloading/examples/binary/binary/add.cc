#include "binary.ih"

void Binary::add(Binary const &other)
{
    cout << d_nr << ':' << d_copy << ".add(" << 
                        other.d_nr << ':' << other.d_copy << ")\n";
}
