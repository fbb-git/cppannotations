#include "ofdnstreambuf.ih"

void OFdNStreambuf::open(int fd, size_t n)
{
    d_fd = fd;
    d_n = (n == 0) ? 1 : n;

    d_buffer = new char[d_n];
    setp(d_buffer, d_buffer + d_n);
}
