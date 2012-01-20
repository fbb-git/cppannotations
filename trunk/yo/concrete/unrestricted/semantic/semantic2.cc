#include "semantic.ih"

Semantic::Semantic(Semantic const &other)
:
    d_int(other.d_int)                      // blunt copy of d_int
{
    if (d_int.first == IDENTIFIER)                 // if a string: copy it
        new (&d_str.second) string(other.d_str.second);
}
