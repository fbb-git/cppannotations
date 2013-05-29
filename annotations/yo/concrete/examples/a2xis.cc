#include "a2x.h"

A2x &A2x::operator=(char const *txt)
{
    clear();        // very important!!! If a conversion failed, the object
                    // remains useless until executing this statement
    str(txt);
    return *this;
}
