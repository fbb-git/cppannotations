    #include <unistd.h>
    #include <streambuf>
    #include <ios>
    #include <algorithm>

//HEAD
    class fdunget: public std::streambuf
    {
        int         d_fd;
        unsigned    d_bufsize;
        unsigned    d_reserved;
        char*       d_buffer;
        char*       d_base;
//=
        public:
//CONS
            fdunget(int fd, unsigned bufsz, unsigned unget)
            :
                d_fd(fd),
                d_reserved(unget)
            {
                unsigned allocate =
                        bufsz > d_reserved ?
                            bufsz
                        :
                            d_reserved + 1;

                d_buffer = new char[allocate];

                d_base = d_buffer + d_reserved;
                setg(d_base, d_base, d_base);

                d_bufsize = allocate - d_reserved;
            }
//=
//DESTR
            ~fdunget()
            {
                delete[] d_buffer;
            }
//=
//UNDERFLOW
            int underflow()
            {
                if (gptr() < egptr())
                    return *gptr();

                unsigned ungetsize = gptr() - eback();
                unsigned move = std::min(ungetsize, d_reserved);

                memcpy(d_base - move, egptr() - move, move);

                int nread = read(d_fd, d_base, d_bufsize);
                if (nread <= 0)       // none read -> return EOF
                    return EOF;

                setg(d_base - move, d_base, d_base + nread);

                return *gptr();
            }
    };
//=
