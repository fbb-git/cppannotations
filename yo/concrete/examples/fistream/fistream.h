#ifndef INCLUDED_FISTREAM_H_
#define INCLUDED_FISTREAM_H_

#include <iosfwd>
#include <istream>
#include <sstream>
#include <fstream>
#include <memory>

/*
    fis >> field(3) >> x    extracts x over max 3 positions.
        First, 3 chars are extracted from fis itself. They are put
        in a separate buffer which is then extracted. What if the extraction
        is not complete? Then a rest remains in the buffer, most likely
        resulting in a failing read, thereafter. Manipulators are provided
        to prevent this: field(0) returns to the non-fixed reading: the
        last field, even if not completely read, is then further ignored.
        field() reads the next field, same width as the previous field. If
        no field has been set before, field() has no effect.
*/

namespace FBB
{

    class field;

//INITIAL
    class Fistream: public std::istream
    {
        std::shared_ptr<std::filebuf> d_filebuf;
        std::streambuf *d_streambuf;
        std::istringstream d_iss;
        size_t d_width;
//=
        public:
//CONS
            Fistream(std::istream &stream);
            Fistream(char const *name,
                std::ios::openmode mode = std::ios::in);
//=
            std::istream &setField(field const &params);
        private:
            void setBuffer();
    };
//FIELD
    class field
    {
        friend class Fistream;
        size_t d_width;
        bool     d_newWidth;

        public:
            field(size_t width);
            field();
    };

    inline field::field(size_t width)
    :
        d_width(width),
        d_newWidth(true)
    {}

    inline field::field()
    :
        d_newWidth(false)
    {}
//=
}   // FBB

//OPEX
namespace std
{
    istream &operator>>(istream &str, FBB::field const &params);
}
//=

#endif
