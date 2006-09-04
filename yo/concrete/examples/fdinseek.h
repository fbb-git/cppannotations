    #include "ifdbuf.h"
    #include <unistd.h>
    #include <ios>

//CLASS
    class ifdseek: public ifdstreambuf
//=
    {
//TYPEDEF
        typedef std::streambuf::pos_type        pos_type;
        typedef std::streambuf::off_type        off_type;
        typedef std::ios::seekdir               seekdir;
        typedef std::ios::openmode              openmode;
//=
        public:
//CONS
            ifdseek(int fd)
            :
                ifdstreambuf(fd)
            {}
//=
//SEEKOFF
            pos_type seekoff(off_type offset, seekdir dir, openmode)
            {
                pos_type pos =
                    lseek
                    (
                        d_fd, offset,
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
            pos_type seekpos(pos_type offset, openmode mode)
            {
                return seekoff(offset, std::ios::beg, mode);
            }
//=
    };
