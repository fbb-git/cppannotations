#ifndef _INCLUDED_PLAINALLOC_H_
#define _INCLUDED_PLAINALLOC_H_

#include <ostream>

template <typename Data>
class PlainAlloc
{
    template<typename IData>
    friend std::ostream &operator<<(std::ostream &out,
                                    PlainAlloc<IData> const &alloc);
    Data d_data;

    public:
        PlainAlloc();
        PlainAlloc(Data data);
        PlainAlloc(PlainAlloc<Data> const &other);
        operator Data &();
        PlainAlloc &operator=(Data const &data);
};

template <typename Data>
PlainAlloc<Data>::PlainAlloc()
{}

template <typename Data>
PlainAlloc<Data>::PlainAlloc(Data data)
:
    d_data(data)
{}

template <typename Data>
PlainAlloc<Data>::PlainAlloc(PlainAlloc<Data> const &other)
:
    d_data(other.d_data)
{}

template <typename Data>
PlainAlloc<Data>::operator Data &()
{
    return d_data;
}

template <typename Data>
PlainAlloc<Data> &PlainAlloc<Data>::operator=(Data const &data)
{
    d_data = data;
}

template<typename IData>
inline std::ostream &operator<<(std::ostream &out,
                                PlainAlloc<IData> const &alloc)
{
    return out << alloc.d_data;
}



#endif
