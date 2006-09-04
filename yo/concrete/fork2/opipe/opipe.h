#ifndef _INCLUDED_OPIPE_H_
#define _INCLUDED_OPIPE_H_

#ifndef _INCLUDED_PIPE_H_
#include "../pipe/pipe.h"
#endif

#ifndef _INCLUDED_OFDNSTREAMBUF_H_
#include "../ofdnstreambuf/ofdnstreambuf.h"
#endif

#ifndef _INCLUDED_OSTREAM_
#include <ostream>
#define _INCLUDED_OSTREAM_
#endif


namespace FBB
{
    class OPipe: public Pipe, private OFdNStreambuf, public std::ostream
    {
        public:
            OPipe(unsigned size = 500);
    };
}

#endif
