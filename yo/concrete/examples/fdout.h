    #ifndef _OFDNSTREAMBUF_H_
    #define _OFDNSTREAMBUF_H_

    #include <unistd.h>
    #include <streambuf>

//HEAD
    class ofdnstreambuf: public std::streambuf
//=
    {
//DATA
        unsigned d_bufsize;
        int     d_fd;
        char    *d_buffer;
//=

        public:
//CONS
            ofdnstreambuf()
            :
                d_bufsize(0),
                d_buffer(0)
            {}
            ofdnstreambuf(int fd, unsigned bufsize = 1)
            {
                open(fd, bufsize);
            }
//=
//DESTR
            ~ofdnstreambuf()
            {
                if (d_buffer)
                {
                    sync();
                    delete[] d_buffer;
                }
            }
//=
//OPEN
            void open(int fd, unsigned bufsize = 1)
            {
                d_fd = fd;
                d_bufsize = bufsize == 0 ? 1 : bufsize;

                d_buffer = new char[d_bufsize];
                setp(d_buffer, d_buffer + d_bufsize);
            }
//=
//SYNC
            int sync()
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
            int overflow(int c)
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
    };

    #endif
