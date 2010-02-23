#include "fistream.ih"

//OPEX
istream &std::operator>>(istream &str, field const &params)
{
    return reinterpret_cast<Fistream *>(&str)->setField(params);
}
//=

//CONS1
Fistream::Fistream(istream &stream)
:
    istream(stream.rdbuf()),
    d_streambuf(rdbuf()),
    d_width(0)
{}
//=
//CONS2
Fistream::Fistream(char const *name, ios::openmode mode)
:
    istream(new filebuf()),
    d_filebuf(reinterpret_cast<filebuf *>(rdbuf())),
    d_streambuf(d_filebuf.get()),
    d_width(0)
{
    d_filebuf->open(name, mode);
}
//=
//SETFIELD
std::istream &Fistream::setField(field const &params)
{
    if (params.d_newWidth)                  // new field size requested
        d_width = params.d_width;           // set new width

    if (!d_width)                           // no width?
        rdbuf(d_streambuf);                 // return to the old buffer
    else
        setBuffer();                        // define the extraction buffer

    return *this;
}
//=
//SETBUFFER
void Fistream::setBuffer()
{
    char *buffer = new char[d_width + 1];

    rdbuf(d_streambuf);                     // use istream's buffer to
    buffer[read(buffer, d_width).gcount()] = 0; // read d_width chars,
                                                // terminated by ascii-Z
    d_iss.str(buffer);
    delete buffer;

    rdbuf(d_iss.rdbuf());                   // switch buffers
}
//=
