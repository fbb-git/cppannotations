#ifndef _INCLUDED_IFDNSTREAMBUF_H_
#define _INCLUDED_IFDNSTREAMBUF_H_

#ifndef _INCLUDED_STREAMBUF_
#include <streambuf>
#define _INCLUDED_STREAMBUF_
#endif

namespace FBB
{
    class IFdNStreambuf: public std::streambuf
    {
        private:
            int         d_fd;
            unsigned    d_n;
            char*       d_buffer;

        public:
            IFdNStreambuf()
            :
                d_n(0),
                d_buffer(0)
            {}

            IFdNStreambuf(int fd, unsigned n = 1)
            {
                open(fd, n);
            }

            ~IFdNStreambuf();

            void open(int xfd, unsigned n = 1);
            int underflow();
            std::streamsize xsgetn(char *dest, std::streamsize n);

        private:
            IFdNStreambuf(IFdNStreambuf const &other);              // NI
            IFdNStreambuf &operator=(IFdNStreambuf const &other);   // NI
    };
}

#endif
