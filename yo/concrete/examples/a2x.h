#ifndef _INCLUDED_A2X_H_
#define _INCLUDED_A2X_H_

#include <sstream>
#include <string>

//HEAD
class A2x: public std::istringstream
//=
{
    public:
//CONS
        A2x()
        {}
        A2x(std::string const &str)
        :
            std::istringstream(str)
        {}
//=
//TYPE
        template <typename Type>
        operator Type()
        {
            Type t;

            return (*this >> t) ? t : Type();
        }
//=
//TO
        template <typename Type>
        Type to(Type const&)
        {
            return *this;
        }
//=
        A2x &operator=(std::string const &str);
//OP=
        A2x &operator=(A2x const &other)
        {
            return operator=(other.str());
        }
//=
};



#endif
