#ifndef _INCLUDED_STRINGPTR_H_
#define _INCLUDED_STRINGPTR_H_

#include <string>
#include <vector>
#include <iterator>

//HEAD
class StringPtr: public std::vector<std::string *>
{
    typedef std::iterator<std::random_access_iterator_tag, std::string>
            Iterator;

    public:
    class iterator: public Iterator
//=
    {
//PRIVATE
        friend class StringPtr;

        std::vector<std::string *>::iterator d_current;

        iterator(std::vector<std::string *>::iterator const &current)
        :
            d_current(current)
        {}
//=
        public:
//PREDEC
            iterator &operator--()
            {
                --d_current;
                return *this;
            }
//=
//POSTDEC
            iterator const operator--(int)
            {
                return iterator(d_current--);
            }
//=
//PREINC
            iterator &operator++()
            {
                ++d_current;
                return *this;
            }
//=
//OPEQ
            bool operator==(iterator const &other) const
            {
                return d_current == other.d_current;
            }
//=
//OPNEQ
            bool operator!=(iterator const &other) const
            {
                return d_current != other.d_current;
            }
//
//OPSUB
            int operator-(iterator const &rhs) const
            {
                return d_current - rhs.d_current;
            }
//=
//OP*
            std::string &operator*() const
            {
                return **d_current;
            }
//=
//CMP
            bool operator<(iterator const &other) const
            {
                return **d_current < **other.d_current;
            }
//=
//OPADD
            iterator const operator+(int step) const
            {
                return iterator(d_current + step);
            }
//=
//OP-
            iterator const operator-(int step) const
            {
                return iterator(d_current - step);
            }
//=
//OPARITH
            iterator &operator+=(int step)  // increment the iterator
            {                               // over `n' steps
                d_current += step;
                return *this;
            }
            iterator &operator-=(int step)  // decrement the iterator
            {                               // over `n' steps
                d_current -= step;
                return *this;
            }
//=
//OPARROW
            std::string *operator->() const // access the fields of the
            {                               // struct an iterator points
                return *d_current;          // to. E.g., it->length()
            }
//=
    };

    typedef std::reverse_iterator<iterator> reverse_iterator;
//BEGEND
    iterator begin()
    {
        return iterator(this->std::vector<std::string *>::begin());
    }
    iterator end()
    {
        return iterator(this->std::vector<std::string *>::end());
    }
//=
//RBEGEND
    reverse_iterator rbegin()
    {
        return reverse_iterator(end());
    }
    reverse_iterator rend()
    {
        return reverse_iterator(begin());
    }
//=
};

#endif
