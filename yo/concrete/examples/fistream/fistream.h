#ifndef _INCLUDED_FISTREAM_H_
#define _INCLUDED_FISTREAM_H_

#include <iosfwd>
#include <istream>
#include <sstream>
#include <fstream>

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
    class fistream: public std::istream
    {
        std::auto_ptr<std::filebuf> d_filebuf;
        std::streambuf *d_streambuf;
        std::istringstream d_iss;
        unsigned d_width;
//=
        public:
//CONS
            fistream(std::istream &stream);
            fistream(char const *name,
                std::ios::openmode mode = std::ios::in);
//=
            std::istream &setField(field const &params);
        private:
            void setBuffer();
    };

//FIELD
    class field
    {
        friend class fistream;
        unsigned d_width;
        bool     d_newWidth;

        public:
            field(unsigned width)
            :
                d_width(width),
                d_newWidth(true)
            {}
            field()
            :
                d_newWidth(false)
            {}
    };
//=

}   // FBB

//OPEX
namespace std
{
    istream &operator>>(istream &str, FBB::field const &params);
}
//=

#endif
