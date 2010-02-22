    #ifndef OFDNSTREAMBUF_H_
    #define OFDNSTREAMBUF_H_

    #include <unistd.h>
    #include <streambuf>

//CLASS
    class OFdnStreambuf: public std::streambuf
    {
        size_t d_bufsize;
        int     d_fd;
        char    *d_buffer;

        public:
            OFdnStreambuf();
            OFdnStreambuf(int fd, size_t bufsize = 1);
            virtual ~OFdnStreambuf();
            void open(int fd, size_t bufsize = 1);
        private:
            virtual int sync();
            virtual int overflow(int c);
    };
//=

//CONS
    inline OFdnStreambuf::OFdnStreambuf()
    :
        d_bufsize(0),
        d_buffer(0)
    {}
    inline OFdnStreambuf::OFdnStreambuf(int fd, size_t bufsize)
    {
        open(fd, bufsize);
    }
//=
//DESTR
    inline OFdnStreambuf::~OFdnStreambuf()
    {
        if (d_buffer)
        {
            sync();
            delete[] d_buffer;
        }
    }
//=
//OPEN
    inline void OFdnStreambuf::open(int fd, size_t bufsize)
    {
        d_fd = fd;
        d_bufsize = bufsize == 0 ? 1 : bufsize;

        d_buffer = new char[d_bufsize];
        setp(d_buffer, d_buffer + d_bufsize);
    }
//=
//SYNC
    inline int OFdnStreambuf::sync()
    {
        if (pptr() > pbase())
        {
            write(d_fd, d_buffer, pptr() - pbase());
            setp(d_buffer, d_buffer + d_bufsize);
        }
        return 0;
    }
//=
//OVERFLOW
    inline int OFdnStreambuf::overflow(int c)
    {
        sync();
        if (c != EOF)
        {
            *pptr() = c;
            pbump(1);
        }
        return c;
    }
//=

    #endif
