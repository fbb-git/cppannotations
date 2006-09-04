#ifndef _INCLUDED_OFDNSTREAMBUF_H_
#define _INCLUDED_OFDNSTREAMBUF_H_

#ifndef _INCLUDED_STREAMBUF_
#include <streambuf>
#define _INCLUDED_STREAMBUF_
#endif

namespace FBB
{
    class OFdNStreambuf: public std::streambuf
    {
        private:
            unsigned    d_n;
            int         d_fd;
            char       *d_buffer;

        public:
            OFdNStreambuf()
            :
                d_n(0),
                d_buffer(0)
            {}

            OFdNStreambuf(int fd, unsigned n = 1)
            {
                open(fd, n);
            }

            ~OFdNStreambuf();

            void open(int fd, unsigned n = 1);
            int sync();
            int overflow(int c);

        private:
            OFdNStreambuf(OFdNStreambuf const &other);              // NI
            OFdNStreambuf &operator=(OFdNStreambuf const &other);   // NI
    };
}

#endif
