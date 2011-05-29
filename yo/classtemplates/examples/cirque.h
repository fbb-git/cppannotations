#ifndef INCLUDED_CIRQUE_H_
#define INCLUDED_CIRQUE_H_

#include <memory>
#include <cstring>
#include <algorithm>

template<typename Data>
class CirQue
{
//DATA
    size_t d_size;
    size_t d_maxSize;
    Data *d_data;
    Data *d_front;
    Data *d_back;
//=

    public:
//TYPEDEFS
    typedef Data value_type;
    typedef value_type const &const_reference;
//=

//EXCEPTION
    enum Exception
    {
        EMPTY,
        FULL
    };
//=
        explicit CirQue(size_t maxSize = 0);
        CirQue(CirQue<Data> const &other);
        CirQue(CirQue<Data> &&tmp);

        template <size_t Size>
        explicit CirQue(Data const (&arr)[Size]);

        explicit CirQue(Data const *data, size_t size);

        ~CirQue();

        CirQue &operator=(CirQue<Data> const &other);
        CirQue &operator=(CirQue<Data> &&tmp);

        Data &back();
        Data &front();
        bool empty() const;
        bool full() const;
        size_t maxSize() const;
        size_t size() const;
        void pop_front();
        void push_back(Data const &object);
        void swap(CirQue<Data> &other);

    private:
        Data *inc(Data *ptr);
};

//CIRQUE
    template<typename Data>
    CirQue<Data>::CirQue(size_t maxSize)
    :
        d_size(0),
        d_maxSize(maxSize),
        d_data(
            maxSize == 0 ?
                0
            :
                static_cast<Data *>(
                            operator new(maxSize * sizeof(Data)))
        ),
        d_front(d_data),
        d_back(d_data)
    {}
//=

//COPYCONS
    template<typename Data>
    CirQue<Data>::CirQue(CirQue<Data> const &other)
    :
        d_size(other.d_size),
        d_maxSize(other.d_maxSize),
        d_data(
            d_maxSize == 0 ?
                0
            :
                static_cast<Data *>(
                    operator new(d_maxSize * sizeof(Data)))
        ),
        d_front(d_data + (other.d_front - other.d_data))
    {
        Data const *src = other.d_front;
        d_back = d_front;
        for (size_t count = 0; count != d_size; ++count)
        {
            new(d_back) Data(*src);
            d_back = inc(d_back);
            if (++src == other.d_data + d_maxSize)
                src = other.d_data;
        }
    }
//=

//MOVECONS
    template<typename Data>
    CirQue<Data>::CirQue(CirQue<Data> &&tmp)
    :
        d_data(0)
    {
        swap(tmp);
    }
//=

//MEMBER
    template <typename Data>
    template <size_t Size>
    CirQue<Data>::CirQue(Data const (&arr)[Size])
    :
        d_size(0),
        d_maxSize(Size),
        d_data(static_cast<Data *>(operator new(sizeof(arr)))),
        d_front(d_data),
        d_back(d_data)
    {
        std::copy(arr, arr + Size, back_inserter(*this));
    }
//=
//DESTRUCTOR
    template<typename Data>
    CirQue<Data>::~CirQue()
    {
        if (d_data == 0)
            return;
        for (; d_size--; )
        {
            d_front->~Data();
            d_front = inc(d_front);
        }
        operator delete(d_data);
    }
//=

//COPYASSIGN
    template<typename Data>
    CirQue<Data> &CirQue<Data>::operator=(CirQue<Data> const &rhs)
    {
        CirQue<Data> tmp(rhs);
        swap(tmp);
    }
//=

//MOVEASSIGN
    template<typename Data>
    inline CirQue<Data> &CirQue<Data>::operator=(CirQue<Data> &&tmp)
    {
        swap(tmp);
    }
//=

//SWAP
    template<typename Data>
    void CirQue<Data>::swap(CirQue<Data> &other)
    {
        char tmp[sizeof(CirQue<Data>)];
        memcpy(tmp, &other, sizeof(CirQue<Data>));
        memcpy(&other, this, sizeof(CirQue<Data>));
        memcpy(this, tmp, sizeof(CirQue<Data>));
    }
//=

//POPFRONT
    template<typename Data>
    void CirQue<Data>::pop_front()
    {
        if (d_size == 0)
            throw EMPTY;

        d_front->~Data();
        d_front = inc(d_front);
        --d_size;
    }
//=


//PUSHBACK
    template<typename Data>
    void CirQue<Data>::push_back(Data const &object)
    {
        if (d_size == d_maxSize)
            throw FULL;

        new (d_back) Data(object);
        d_back = inc(d_back);
        ++d_size;
    }
//=


//BACK
    template<typename Data>
    inline Data &CirQue<Data>::back()
    {
        return d_back == d_data ? d_data[d_maxSize - 1] : d_back[-1];
    }
//=

//FRONT
    template<typename Data>
    inline Data &CirQue<Data>::front()
    {
        return *d_front;
    }
//=

//EMPTY
    template<typename Data>
    inline bool CirQue<Data>::empty() const
    {
        return d_size == 0;
    }
//=

//FULL
    template<typename Data>
    inline bool CirQue<Data>::full() const
    {
        return d_size == d_maxSize;
    }
//=

//SIZE
    template<typename Data>
    inline size_t CirQue<Data>::size() const
    {
        return d_size;
    }
//=

//MAXSIZE
    template<typename Data>
    inline size_t CirQue<Data>::maxSize() const
    {
        return d_maxSize;
    }
//=

//INC
    template<typename Data>
    Data *CirQue<Data>::inc(Data *ptr)
    {
        ++ptr;
        return ptr == d_data + d_maxSize ? d_data : ptr;
    }
//=

#endif
