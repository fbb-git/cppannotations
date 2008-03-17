#ifndef INCLUDED_SEMANTIC_
#define INCLUDED_SEMANTIC_

#include <ostream>

#include "../base/base.h"

class Semantic
{
    Base *d_bp;

    public:
        Semantic(Base *bp = 0);             // Semantic will own the bp
        Semantic(Semantic const &other);
        ~Semantic();

        Semantic &operator=(Semantic const &other);

        Base const &base() const;

        template <typename Class>
        Class const &downcast();

    private:
        void copy(Semantic const &other);
};

inline Base const &Semantic::base() const
{
    return *d_bp;
}

inline Semantic::Semantic(Base *bp)
:
    d_bp(bp)
{}

inline Semantic::~Semantic()
{
    delete d_bp;
}
       
inline Semantic::Semantic(Semantic const &other)
{
    copy(other);
}

inline Semantic &Semantic::operator=(Semantic const &other)
{
    if (this != &other)
    {
        delete d_bp;
        copy(other);        
    }
    return *this;
}

inline void Semantic::copy(Semantic const &other)
{
    d_bp = other.d_bp ? other.d_bp->clone() : 0;
}

template <typename Class>
inline  Class const &Semantic::downcast()
{
    return dynamic_cast<Class &>(*d_bp);
}

inline std::ostream &operator<<(std::ostream &out, Semantic const &obj)
{
    if (&obj.base())
        return out << obj.base();

    return out << "<UNDEFINED>";
}

#endif
