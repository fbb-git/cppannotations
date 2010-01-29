#ifndef INCLUDED_CIRQUEVECTOR_H_
#define INCLUDED_CIRQUEVECTOR_H_

#include <vector>
#include "cirque.h"

template<>
class CirQue<std::vector<int>>
{
    typedef std::vector<int> IntVect;

    IntVect d_data;
    size_t d_size;

    typedef IntVect::iterator iterator;
    iterator d_front;
    iterator d_back;

    public:
        typedef int value_type;
        typedef value_type const &const_reference;
    
        enum Exception
        {
            EMPTY,
            FULL
        };

        CirQue();
        CirQue(IntVect const &iv);
        CirQue(CirQue<IntVect> const &other);

        CirQue &operator=(CirQue<IntVect> const &other);
    
        int &back();
        int &front();
        bool empty() const;
        bool full() const;
        size_t maxSize() const;
        size_t size() const;
        void pop_front();
        void push_back(int const &object);
        void swap(CirQue<IntVect> &other);

    private:
        iterator inc(iterator const &iter); 
};

CirQue<std::vector<int>>::CirQue()
:
    d_size(0)
{}
CirQue<std::vector<int>>::CirQue(IntVect const &iv)
:
    d_data(iv),
    d_size(iv.size()),
    d_front(d_data.begin()),
    d_back(d_data.begin())
{}
CirQue<std::vector<int>>::CirQue(CirQue<IntVect> const &other)
:
    d_data(other.d_data),
    d_size(other.d_size),
    d_front(d_data.begin() + (other.d_front - other.d_data.begin())),
    d_back(d_data.begin() + (other.d_back - other.d_data.begin()))
{}
CirQue<std::vector<int>> &CirQue<std::vector<int>>::operator=(
                                        CirQue<IntVect> const &rhs)
{
    CirQue<IntVect> tmp(rhs);
    swap(tmp);
}
void CirQue<std::vector<int>>::swap(CirQue<IntVect> &other)
{
    char tmp[sizeof(CirQue<IntVect>)];
    memcpy(tmp, &other, sizeof(CirQue<IntVect>));
    memcpy(&other, this, sizeof(CirQue<IntVect>));
    memcpy(this, tmp, sizeof(CirQue<IntVect>));
}
void CirQue<std::vector<int>>::pop_front()
{
    if (d_size == 0)
        throw EMPTY;

    d_front = inc(d_front);
    --d_size;
}
void CirQue<std::vector<int>>::push_back(int const &object)
{
    if (d_size == d_data.size())
        throw FULL;

    *d_back = object;
    d_back = inc(d_back);
    ++d_size;
}
inline int &CirQue<std::vector<int>>::back()
{
    return d_back == d_data.begin() ? d_data.back() : d_back[-1];
}
inline int &CirQue<std::vector<int>>::front()
{
    return *d_front;
}
CirQue<std::vector<int>>::iterator CirQue<std::vector<int>>::inc(
    CirQue<std::vector<int>>::iterator const &iter)
{
    iterator tmp(iter + 1);
    tmp =  tmp == d_data.end() ? d_data.begin() : tmp;
    return tmp;
}

#endif
