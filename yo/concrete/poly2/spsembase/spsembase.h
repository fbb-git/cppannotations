#ifndef INCLUDED_SPSEMBASE_
#define INCLUDED_SPSEMBASE_

#include "../sembase/sembase.h"

class spSemBase: public std::shared_ptr<SemBase>
{
    public:
        spSemBase() = default;

        template <typename Type>
        spSemBase(Type *obj);
};
        
template <typename Type>
inline spSemBase::spSemBase(Type *obj)
:
    std::shared_ptr<SemBase>(obj)
{}

#endif
