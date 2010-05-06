#ifndef INCLUDED_SEMANTIC_
#define INCLUDED_SEMANTIC_

#include <memory>
#include <ostream>

#include "../base/base.h"

class Semantic: public std::shared_ptr<Base>
{
    friend std::ostream &operator<<(std::ostream &out, Semantic const &obj);

    public:
        Semantic(Base *bp = 0);             // Semantic owns the bp
        ~Semantic() = default;
};

inline Semantic::Semantic(Base *bp)
:
    std::shared_ptr<Base>(bp)
{}

inline std::ostream &operator<<(std::ostream &out, Semantic const &obj)
{
    if (obj)
        return out << *obj;

    return out << "<UNDEFINED>";
}

#endif
