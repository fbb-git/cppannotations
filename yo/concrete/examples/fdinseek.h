    #include "ifdbuf.h"
    #include <unistd.h>
    #include <ios>

//CLASS
    class ifdseek: public IFdStreambuf
    {
        typedef std::streambuf::pos_type        pos_type;
        typedef std::streambuf::off_type        off_type;
        typedef std::ios::seekdir               seekdir;
        typedef std::ios::openmode              openmode;

        public:
            ifdseek(int fd);
            pos_type seekoff(off_type offset, seekdir dir, openmode);
            pos_type seekpos(pos_type offset, openmode mode);
    };
//=
//CONS
    inline ifdseek::ifdseek(int fd)
    :
        IFdStreambuf(fd)
    {}
//=
//SEEKOFF
    ifdseek::pos_type ifdseek::seekoff(off_type off, seekdir dir, openmode)
    {
        pos_type pos =
            lseek
            (
                d_fd, off,
                (dir ==  std::ios::beg) ? SEEK_SET :
                (dir ==  std::ios::cur) ? SEEK_CUR :
                                          SEEK_END
            );

        if (pos < 0)
            return -1;

        setg(d_buffer, d_buffer + 1, d_buffer + 1);
        return pos;
    }
//=
//SEEKPOS
    inline ifdseek::pos_type ifdseek::seekpos(pos_type off, openmode mode)
    {
        return seekoff(off, std::ios::beg, mode);
    }
//=
