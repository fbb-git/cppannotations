    #ifndef _IFDNBUF_H_
    #define _IFDNBUF_H_

    #include <unistd.h>
    #include <streambuf>
//CLASS
    class ifdnstreambuf: public std::streambuf
//=
    {
//DATA
        protected:
            int         d_fd;
            size_t    d_bufsize;
            char*       d_buffer;
//=
        public:
//CONS
            ifdnstreambuf()
            :
                d_bufsize(0),
                d_buffer(0)
            {}
            ifdnstreambuf(int fd, size_t bufsize = 1)
            {
                open(fd, bufsize);
            }
//=
//DESTR
            ~ifdnstreambuf()
            {
                if (d_bufsize)
                {
                    close(d_fd);
                    delete[] d_buffer;
                }
            }
//=
//OPEN
            void open(int fd, size_t bufsize = 1)
            {
                d_fd = fd;
                d_bufsize = bufsize;
                d_buffer = new char[d_bufsize];
                setg(d_buffer, d_buffer + d_bufsize, d_buffer + d_bufsize);
            }
//=
//UFLOW
            int underflow()
            {
                if (gptr() < egptr())
                    return *gptr();

                int nread = read(d_fd, d_buffer, d_bufsize);

                if (nread <= 0)
                    return EOF;

                setg(d_buffer, d_buffer, d_buffer + nread);
                return *gptr();
            }
//=
//XSGETN
            std::streamsize xsgetn(char *dest, std::streamsize n)
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
    };

    #endif
