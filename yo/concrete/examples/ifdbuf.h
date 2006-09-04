    #include <unistd.h>
    #include <streambuf>
//CLASS
    class ifdstreambuf: public std::streambuf
//=
    {
//DATA
        protected:
            int     d_fd;
            char    d_buffer[1];
//=
        public:
//CONS
            ifdstreambuf(int fd)
            :
                d_fd(fd)
            {
                setg(d_buffer, d_buffer + 1, d_buffer + 1);
            }
//=
//UFLOW
            int underflow()
            {
                if (gptr() < egptr())
                    return *gptr();

                if (read(d_fd, d_buffer, 1) <= 0)
                    return EOF;

                setg(d_buffer, d_buffer, d_buffer + 1);
                return *gptr();
            }
//=
    };
