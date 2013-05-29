#include <unistd.h>
#include <streambuf>
#include <ios>

       #include <sys/types.h>
       #include <unistd.h>

#include <iostream>
using namespace std;

class fdstreambuf: public std::streambuf
{
    public:
        fdstreambuf(int fd, std::ios::openmode mode =
                                std::ios::in | std::ios::out)
        :
            fd(fd)
        {
            if (mode & std::ios::in)
                setg(buffer, buffer + 1, buffer + 1);
        }

        pos_type
        seekoff(off_type offset, ios::seekdir dir,
            ios_base::openmode)
        {
            pos_type
                pos =
                    lseek
                    (
                        fd, offset,
                        (dir ==  ios::beg) ? SEEK_SET :
                        (dir ==  ios::cur) ? SEEK_CUR :
                                             SEEK_END
                    );

            if (pos < 0)
                return -1;

            setg(buffer, buffer + 1, buffer + 1);
            return pos;
        }

        pos_type                        // used by seekg()
        seekpos(pos_type offset, ios_base::openmode mode)
        {
            return seekoff(offset, ios::beg, mode);
        }

        int underflow()             // inspects the character
        {
            if (gptr() < egptr())
                return *gptr();     // return next char waiting in the buffer

            if (read(fd, buffer, 1) <= 0)       // none read ->
            {
                return EOF;
            }

            setg(buffer, buffer, buffer + 1);
            return *gptr();
        }

    private:
        char
            buffer[1];
        int
            fd;
};
