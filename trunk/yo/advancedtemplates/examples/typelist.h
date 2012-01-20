#ifndef INCLUDED_TYPELIST_H_
#define INCLUDED_TYPELIST_H_

//TYPELIST
    template <typename ...Types>
    struct TypeList
    {
        TypeList(TypeList const &) = delete;
        enum { size = sizeof ...(Types) };
    };
//=


#endif
