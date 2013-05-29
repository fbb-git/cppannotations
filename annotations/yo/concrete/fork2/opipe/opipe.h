#ifndef INCLUDED_OPIPE_H_
#define INCLUDED_OPIPE_H_

#ifndef INCLUDED_PIPE_H_
#include "../pipe/pipe.h"
#endif

#ifndef INCLUDED_OFDNSTREAMBUF_H_
#include "../ofdnstreambuf/ofdnstreambuf.h"
#endif

#ifndef INCLUDED_OSTREAM_
#include <ostream>
#define INCLUDED_OSTREAM_
#endif


namespace FBB
{
    class OPipe: public Pipe, private OFdNStreambuf, public std::ostream
    {
        public:
            OPipe(size_t size = 500);
    };
}

#endif
