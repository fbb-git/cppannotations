#ifndef INCLUDED_PLACEMENTALLOC_H_
#define INCLUDED_PLACEMENTALLOC_H_

#include <ostream>

template<typename Data>
class PlacementAlloc
{
    template<typename IData>
    friend std::ostream &operator<<(std::ostream &out,
                                    PlacementAlloc<IData> const &alloc);
    Data *d_data;

    static char s_commonPool[];
    static char *s_free;

    public:
        PlacementAlloc();
        PlacementAlloc(Data const &data);
        PlacementAlloc(PlacementAlloc<Data> const &other);
        ~PlacementAlloc();
        operator Data &();
        PlacementAlloc &operator=(Data const &data);
    private:
        char *request();
};

template<typename Data>
char PlacementAlloc<Data>::s_commonPool[1000];

template<typename Data>
char *PlacementAlloc<Data>::s_free =
        PlacementAlloc<Data>::s_commonPool;

template<typename Data>
PlacementAlloc<Data>::PlacementAlloc()
:
    d_data(0)
{}

template<typename Data>
PlacementAlloc<Data>::PlacementAlloc(Data const &data)
:
    d_data(new(request()) Data(data))
{}

template<typename Data>
PlacementAlloc<Data>::PlacementAlloc(PlacementAlloc<Data> const &other)
:
    d_data(new(request()) Data(*other.d_data))
{}

template<typename Data>
PlacementAlloc<Data>::~PlacementAlloc()
{
    d_data->~Data();
}

template<typename Data>
PlacementAlloc<Data>::operator Data &()
{
    return *d_data;
}

template<typename Data>
PlacementAlloc<Data> &PlacementAlloc<Data>::operator=(Data const &data)
{
    *d_data = data;
}

template<typename Data>
char *PlacementAlloc<Data>::request()
{
    char *cp = s_free;
    s_free += sizeof(Data);
    return cp;
}

template<typename IData>
inline std::ostream &operator<<(std::ostream &out,
                                PlacementAlloc<IData> const &alloc)
{
    return out << *alloc.d_data;
}

#endif
