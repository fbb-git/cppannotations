#include "semantic.ih"

Semantic::~Semantic()
{
    if (d_int.first == IDENTIFIER)
        d_str.second.~string();         // destroy the string's memory
}
