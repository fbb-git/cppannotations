#include "semantic.ih"

Semantic &Semantic::operator=(Semantic const &rhs)
{
    Semantic tmp(rhs);
    swap(tmp);
    return *this;
}
