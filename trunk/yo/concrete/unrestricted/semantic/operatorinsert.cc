#include "semantic.ih"

std::ostream &operator<<(std::ostream &out, Semantic const &obj)
{
    if (obj.d_int.first == Semantic::IDENTIFIER)
        out << obj.d_str.second;
    else
        out << obj.d_int.second;

    return out;
}
