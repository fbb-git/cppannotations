#ifndef _INCLUDED_IPIPE_H_
#define _INCLUDED_IPIPE_H_

#ifndef _INCLUDED_PIPE_H_
#include "../pipe/pipe.h"
#endif

#ifndef _INCLUDED_ISTREAM_
#include <istream>
#define _INCLUDED_ISTREAM_
#endif

namespace FBB
{
    class IPipe: virtual public Pipe
    {
        private:
            IfdNstreambuf d_ibuf;
            std::istream d_istr;

        public:
            IPipe(unsigned size = 500)
            :
                Pipe(socket),
                d_ibuf(d_fd[READ], size == 0 ? 1 : size),
                d_istr(&d_ibuf)
            {}
            IPipe(int socket, unsigned size)
            :
                Pipe(socket),
                d_ibuf(d_fd[READ], size == 0 ? 1 : size),
                d_istr(&d_ibuf)
            {}

            istream &istream()
            {
                return d_istr;
            }
    };
}

#endif
