#ifndef INCLUDED_STRINGPTR_H_
#define INCLUDED_STRINGPTR_H_

#include <string>
#include <vector>
#include <iterator>

//STRINGPTR
class StringPtr: public std::vector<std::string *>
{
    public:
    class iterator: public
            std::iterator<std::random_access_iterator_tag, std::string>
    {
        friend class StringPtr;
        std::vector<std::string *>::iterator d_current;

        iterator(std::vector<std::string *>::iterator const &current);

        public:
            iterator &operator--();
            iterator operator--(int);
            iterator &operator++();
            iterator operator++(int);
            bool operator==(iterator const &other) const;
            bool operator!=(iterator const &other) const;
            int operator-(iterator const &rhs) const;
            std::string &operator*() const;
            bool operator<(iterator const &other) const;
            iterator operator+(int step) const;
            iterator operator-(int step) const;
            iterator &operator+=(int step); // increment over `n' steps
            iterator &operator-=(int step); // decrement over `n' steps
            std::string *operator->() const;// access the fields of the
                                            // struct an iterator points
                                            // to. E.g., it->length()
    };

    typedef std::reverse_iterator<iterator> reverse_iterator;

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};
//=

//PRIVATEIMP
inline StringPtr::iterator::iterator(
    std::vector<std::string *>::iterator const &current)
:
    d_current(current)
{}
//=

//PREDEC
inline StringPtr::iterator &StringPtr::iterator::operator--()
{
    --d_current;
    return *this;
}
//=
//POSTDEC
inline StringPtr::iterator const StringPtr::iterator::operator--(int)
{
    return iterator(d_current--);
}
//=
//PREINC
inline StringPtr::iterator &StringPtr::iterator::operator++()
{
    ++d_current;
    return *this;
}
//=
//POSTINC
inline StringPtr::iterator const StringPtr::iterator::operator++(int)
{
    return iterator(d_current++);
}
//=
//OPEQ
inline bool StringPtr::iterator::operator==(iterator const &other) const
{
    return d_current == other.d_current;
}
//=
//OPNEQ
inline bool StringPtr::iterator::operator!=(iterator const &other) const
{
    return d_current != other.d_current;
}
//
//OPSUB
inline int StringPtr::iterator::operator-(iterator const &rhs) const
{
    return d_current - rhs.d_current;
}
//=
//OP*
inline std::string &StringPtr::iterator::operator*() const
{
    return **d_current;
}
//=
//CMP
inline bool StringPtr::iterator::operator<(iterator const &other) const
{
    return **d_current < **other.d_current;
}
//=
//OPADD
inline StringPtr::iterator const
        StringPtr::iterator::operator+(int step) const
{
    return iterator(d_current + step);
}
//=
//OP-
inline StringPtr::iterator const
       StringPtr::iterator::operator-(int step) const
{
    return iterator(d_current - step);
}
//=
//OPARITH
inline StringPtr::iterator &StringPtr::iterator::operator+=(int step)
{
    d_current += step;
    return *this;
}
inline StringPtr::iterator &StringPtr::iterator::operator-=(int step)
{
    d_current -= step;
    return *this;
}
//=
//OPARROW
inline std::string *StringPtr::iterator::operator->() const
{
    return *d_current;
}
//=
//BEGEND
inline StringPtr::iterator StringPtr::begin()
{
    return iterator(this->std::vector<std::string *>::begin());
}
inline StringPtr::iterator StringPtr::end()
{
    return iterator(this->std::vector<std::string *>::end());
}
//=
//RBEGEND
inline StringPtr::reverse_iterator StringPtr::rbegin()
{
    return reverse_iterator(end());
}
inline StringPtr::reverse_iterator StringPtr::rend()
{
    return reverse_iterator(begin());
}
//=

#endif
