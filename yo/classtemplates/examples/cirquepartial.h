#ifndef INCLUDED_CIRQUEPARTIAL_H_
#define INCLUDED_CIRQUEPARTIAL_H_

#include <vector>
#include "cirque.h"

template<typename Data>
class CirQue<std::vector<Data>>
{
    typedef std::vector<Data> DataVect;

    DataVect d_data;
    size_t d_size;

    typedef typename DataVect::iterator iterator;
    iterator d_front;
    iterator d_back;

    public:
        typedef Data value_type;
        typedef value_type const &const_reference;
    
        enum Exception
        {
            EMPTY,
            FULL
        };

        CirQue();
        CirQue(DataVect const &iv);
        CirQue(CirQue<DataVect> const &other);

        CirQue &operator=(CirQue<DataVect> const &other);
    
        Data &back();
        Data &front();
        bool empty() const;
        bool full() const;
        size_t maxSize() const;
        size_t size() const;
        void pop_front();
        void push_back(Data const &object);
        void swap(CirQue<DataVect> &other);

    private:
        iterator inc(iterator const &iter); 
};

template <typename Data>
CirQue<std::vector<Data>>::CirQue()
:
    d_size(0)
{}
template <typename Data>
CirQue<std::vector<Data>>::CirQue(DataVect const &iv)
:
    d_data(iv),
    d_size(iv.size()),
    d_front(d_data.begin()),
    d_back(d_data.begin())
{}
template <typename Data>
CirQue<std::vector<Data>>::CirQue(CirQue<DataVect> const &other)
:
    d_data(other.d_data),
    d_size(other.d_size),
    d_front(d_data.begin() + (other.d_front - other.d_data.begin())),
    d_back(d_data.begin() + (other.d_back - other.d_data.begin()))
{}
template <typename Data>
CirQue<std::vector<Data>> &CirQue<std::vector<Data>>::operator=(
                                        CirQue<DataVect> const &rhs)
{
    CirQue<DataVect> tmp(rhs);
    swap(tmp);
}
template <typename Data>
void CirQue<std::vector<Data>>::swap(CirQue<DataVect> &other)
{
    char tmp[sizeof(CirQue<DataVect>)];
    memcpy(tmp, &other, sizeof(CirQue<DataVect>));
    memcpy(&other, this, sizeof(CirQue<DataVect>));
    memcpy(this, tmp, sizeof(CirQue<DataVect>));
}
template <typename Data>
void CirQue<std::vector<Data>>::pop_front()
{
    if (d_size == 0)
        throw EMPTY;

    d_front = inc(d_front);
    --d_size;
}
template <typename Data>
void CirQue<std::vector<Data>>::push_back(Data const &object)
{
    if (d_size == d_data.size())
        throw FULL;

    *d_back = object;
    d_back = inc(d_back);
    ++d_size;
}
template <typename Data>
inline Data &CirQue<std::vector<Data>>::back()
{
    return d_back == d_data.begin() ? d_data.back() : d_back[-1];
}
template <typename Data>
inline Data &CirQue<std::vector<Data>>::front()
{
    return *d_front;
}
template <typename Data>
typename CirQue<std::vector<Data>>::iterator CirQue<std::vector<Data>>::inc(
    CirQue<std::vector<Data>>::iterator const &iter)
{
    iterator tmp(iter + 1);
    tmp =  tmp == d_data.end() ? d_data.begin() : tmp;
    return tmp;
}

#endif
