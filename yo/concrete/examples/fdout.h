    #ifndef OFDNSTREAMBUF_H_
    #define OFDNSTREAMBUF_H_

    #include <unistd.h>
    #include <streambuf>

//CLASS
    class ofdnstreambuf: public std::streambuf
    {
        size_t d_bufsize;
        int     d_fd;
        char    *d_buffer;

        public:
            ofdnstreambuf();
            ofdnstreambuf(int fd, size_t bufsize = 1);
            ~ofdnstreambuf();
            void open(int fd, size_t bufsize = 1);
            int sync();
            int overflow(int c);
    };
//=

//CONS
    inline ofdnstreambuf::ofdnstreambuf()
    :
        d_bufsize(0),
        d_buffer(0)
    {}

    inline ofdnstreambuf::ofdnstreambuf(int fd, size_t bufsize)
    {
        open(fd, bufsize);
    }
//=
//DESTR
    inline ofdnstreambuf::~ofdnstreambuf()
    {
        if (d_buffer)
        {
            sync();
            delete[] d_buffer;
        }
    }
//=
//OPEN
    inline void ofdnstreambuf::open(int fd, size_t bufsize)
    {
        d_fd = fd;
        d_bufsize = bufsize == 0 ? 1 : bufsize;

        d_buffer = new char[d_bufsize];
        setp(d_buffer, d_buffer + d_bufsize);
    }
//=
//SYNC
    inline int ofdnstreambuf::sync()
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
    inline int ofdnstreambuf::overflow(int c)
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
