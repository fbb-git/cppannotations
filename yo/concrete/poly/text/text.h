#ifndef INCLUDED_TEXT_
#define INCLUDED_TEXT_

#include <string>
#include <ostream>

#include "../base/base.h"

class Text: public Base
{
    std::string d_text;

    public:
        Text(char const *id);
        virtual Base *clone() const;
        std::string const &id() const;          // directly access the name.
        virtual std::ostream &insert(std::ostream &os) const;
};

inline Text::Text(char const *id)
:
    d_text(id)
{}

inline Base *Text::clone() const 
{
    return new Text(*this);
}

inline std::string const &Text::id() const
{
    return d_text;
}

inline std::ostream &Text::insert(std::ostream &out) const
{
    return out << d_text;
}

#endif
