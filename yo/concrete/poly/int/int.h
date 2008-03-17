#ifndef INCLUDED_INT_
#define INCLUDED_INT_

#include <ostream>

#include <bobcat/a2x>

#include "../base/base.h"

class Int: public Base
{
    int d_value;

    public:
        Int(char const *text);
        Int(int v);
        virtual Base *clone() const;
        int value() const;                // directly access the value
        virtual std::ostream &insert(std::ostream &os) const;
};

inline Int::Int(char const *txt)
:
    d_value(FBB::A2x(txt))
{}

inline Int::Int(int v)
:
    d_value(v)
{}

inline Base *Int::clone() const 
{
    return new Int(*this);
}

inline int Int::value() const
{
    return d_value;
}

inline std::ostream &Int::insert(std::ostream &out) const
{
    return out << d_value;
}

#endif
