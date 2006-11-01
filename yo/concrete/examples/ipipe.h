#ifndef _INCLUDED_IPIPE_H_
#define _INCLUDED_IPIPE_H_

#ifndef _INCLUDED_PIPE_H_
#include "../pipe/pipe.h"
#endif

#ifndef _INCLUDED_IFDSTREAMBUF_H_
#include "../ifdstreambuf/ifdstreambuf.h"
#endif

#ifndef _SYSINC_ISTREAM_
#include <istream>
#define _SYSINC_ISTREAM_
#endif

namespace FBB
{
    class IPipe: public Pipe, private IFdStreambuf, public std::istream
    {
        public:
            IPipe(size_t size = 500);
            void closeWriteFd();
    };
}

#endif
