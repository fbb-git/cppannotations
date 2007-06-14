#ifndef _INCLUDED_NEWALLOC_H_
#define _INCLUDED_NEWALLOC_H_

#include <ostream>

template <typename Data>
class NewAlloc
{
    template<typename IData>
    friend std::ostream &operator<<(std::ostream &out,
                                    NewAlloc<IData> const &alloc);
    Data *d_data;

    public:
        NewAlloc();
        NewAlloc(Data const &data);
        NewAlloc(NewAlloc<Data> const &other);
        ~NewAlloc();
        operator Data &();
        NewAlloc &operator=(Data const &data);
};

template<typename Data>
NewAlloc<Data>::NewAlloc()
:
    d_data(0)
{}

template<typename Data>
NewAlloc<Data>::NewAlloc(Data const &data)
:
    d_data(new Data(data))
{}

template<typename Data>
NewAlloc<Data>::NewAlloc(NewAlloc<Data> const &other)
:
    d_data(new Data(*other.d_data))
{}

template<typename Data>
NewAlloc<Data>::~NewAlloc()
{
    delete d_data;
}

template<typename Data>
NewAlloc<Data>::operator Data &()
{
    return *d_data;
}

template<typename Data>
NewAlloc<Data> &NewAlloc<Data>::operator=(Data const &data)
{
    *d_data = data;
}

template<typename IData>
inline std::ostream &operator<<(std::ostream &out,
                                NewAlloc<IData> const &alloc)
{
    return out << *alloc.d_data;
}


#endif
