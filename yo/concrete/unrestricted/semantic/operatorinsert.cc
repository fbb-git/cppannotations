#include "semantic.ih"

std::ostream &operator<<(std::ostream &out, Semantic const &obj)
{
    switch (obj.d_int.first)
    {
        case Semantic::INT:
        return out << obj.d_int.second;

        case Semantic::IDENTIFIER:
        return out << obj.d_str.second;
    }

    return out << "<*UNDEFINED*>";
}
