#include "base.ih"

Base *Base::clone() const
{
    return ownClone();
}
