#include "ofdnstreambuf.ih"

OFdNStreambuf::~OFdNStreambuf()
{
    if (d_buffer)
    {
        sync();
        delete d_buffer;
    }
}
