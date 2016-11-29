    #ifndef IFDNBUF_H_
    #define IFDNBUF_H_

    #include <unistd.h>
    #include <streambuf>
    #include <cstring>

//CLASS
    class IFdNStreambuf: public std::streambuf
    {
        protected:
            int         d_fd;
            size_t      d_bufsize;
            char*       d_buffer;
        public:
            IFdNStreambuf();
            IFdNStreambuf(int fd, size_t bufsize = 1);
            virtual ~IFdNStreambuf();
            void open(int fd, size_t bufsize = 1);
        private:
            virtual int underflow();
            virtual std::streamsize xsgetn(char *dest, std::streamsize n);
    };
//=

//CONS
    inline IFdNStreambuf::IFdNStreambuf()
    :
        d_bufsize(0),
        d_buffer(0)
    {}
    inline IFdNStreambuf::IFdNStreambuf(int fd, size_t bufsize)
    {
        open(fd, bufsize);
    }
//=

    // In real applications, the following members should be defined in
    // source files. Headers should not have external linkage.

//DESTR
    IFdNStreambuf::~IFdNStreambuf()
    {
        if (d_bufsize)
        {
            close(d_fd);
            delete[] d_buffer;
        }
    }
//=
//OPEN
    void IFdNStreambuf::open(int fd, size_t bufsize)
    {
        d_fd = fd;
        d_bufsize = bufsize;
        d_buffer = new char[d_bufsize];
        setg(d_buffer, d_buffer + d_bufsize, d_buffer + d_bufsize);
    }
//=
//UFLOW
    int IFdNStreambuf::underflow()
    {
        if (gptr() < egptr())
            return *gptr();

        int nread = read(d_fd, d_buffer, d_bufsize);

        if (nread <= 0)
            return EOF;

        setg(d_buffer, d_buffer, d_buffer + nread);
        return static_cast<unsigned char>(*gptr());
    }
//=
//XSGETN
    std::streamsize IFdNStreambuf::xsgetn(char *dest, std::streamsize n)
    {
        int nread = 0;

        while (n)
        {
            if (!in_avail())
            {
                if (underflow() == EOF)
                    break;
            }

            int avail = in_avail();

            if (avail > n)
                avail = n;

            memcpy(dest + nread, gptr(), avail);
            gbump(avail);

            nread += avail;
            n -= avail;
        }

        return nread;
    }
//=

    #endif
