#ifndef INCLUDED_IPIPE_H_
#define INCLUDED_IPIPE_H_

#ifndef INCLUDED_PIPE_H_
#include "../pipe/pipe.h"
#endif

#ifndef INCLUDED_IFDSTREAMBUF_H_
#include "../ifdstreambuf/ifdstreambuf.h"
#endif

#ifndef SYSINC_ISTREAM_
#include <istream>
#define SYSINC_ISTREAM_
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
