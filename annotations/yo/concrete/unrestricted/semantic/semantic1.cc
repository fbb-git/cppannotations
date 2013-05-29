#include "semantic.ih"

Semantic::Semantic(Type type, char const *txt)
{
    d_int.first = static_cast<int>(type);

    if (type == IDENTIFIER)
        new (&d_str.second) string(txt);
    else
    {
        istringstream in(txt);
        in >> d_int.second;
    }
}
