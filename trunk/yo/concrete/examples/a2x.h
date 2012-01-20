#ifndef INCLUDED_A2X_H_
#define INCLUDED_A2X_H_

#include <sstream>
#include <string>

//CLASS
    class A2x: public std::istringstream
    {
        public:
            A2x() = default;
            A2x(char const *txt);
            A2x(std::string const &str);

            template <typename Type>
            operator Type();

            template <typename Type>
            Type to();

            A2x &operator=(char const *txt);

            A2x &operator=(std::string const &str);
            A2x &operator=(A2x const &other);
    };
//=

//CONS
    inline A2x::A2x(char const *txt)        // initialize from text
    :
        std::istringstream(txt)
    {}

    inline A2x::A2x(std::string const &str)
    :
        std::istringstream(str.c_str())
    {}
//=
//TO
    template <typename Type>
    inline Type A2x::to()
    {
        Type t;

        return (*this >> t) ? t : Type();
    }
//=
//TYPE
    template <typename Type>
    inline A2x::operator Type()
    {
        return to<Type>();
    }
//=
    inline A2x &A2x::operator=(std::string const &str)
    {
        return operator=(str.c_str());
    }
//OP=
    inline A2x &A2x::operator=(A2x const &other)
    {
        return operator=(other.str());
    }
//=

#endif
