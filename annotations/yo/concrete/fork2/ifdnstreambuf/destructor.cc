#include "ifdnstreambuf.ih"

IFdNStreambuf::~IFdNStreambuf()
{
    if (d_buffer)
    {
        close(d_fd);
        delete d_buffer;
    }
}
