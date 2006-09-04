#include <unistd.h>
#include <streambuf>
#include <ios>

class fdstreambuf: public std::streambuf
{
    public:
        fdstreambuf(int fd, unsigned bufsize, std::ios::openmode mode =
                                std::ios::in | std::ios::out)
        :
            fd(fd),
            bufsize(bufsize),
            buffer(new char[bufsize])
        {
            if (mode & std::ios::in)
                setg(buffer, buffer + bufsize, buffer + bufsize);
        }

        ~fdstreambuf()
        {
            delete buffer;
        }

        int underflow()             // inspects the character
        {
            if (gptr() < egptr())
                return *gptr();     // return next char waiting in the buffer

            int
                nread = read(fd, buffer, bufsize);

            if (nread <= 0)       // none read ->
                return EOF;

            setg(buffer, buffer, buffer + nread);
            return *gptr();
        }

    private:
        int         fd;
        unsigned    bufsize;
        char*       buffer;
};
