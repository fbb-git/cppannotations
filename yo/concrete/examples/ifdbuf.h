    #include <unistd.h>
    #include <streambuf>
//CLASS
    class ifdstreambuf: public std::streambuf
    {
        protected:
            int     d_fd;
            char    d_buffer[1];
        public:
            ifdstreambuf(int fd);
            int underflow();
    };
//=
//CONS
    inline ifdstreambuf::ifdstreambuf(int fd)
    :
        d_fd(fd)
    {
        setg(d_buffer, d_buffer + 1, d_buffer + 1);
    }
//=
//UFLOW
    inline int ifdstreambuf::underflow()
    {
        if (gptr() < egptr())
            return *gptr();

        if (read(d_fd, d_buffer, 1) <= 0)
            return EOF;

        setg(d_buffer, d_buffer, d_buffer + 1);
        return *gptr();
    }
//=

