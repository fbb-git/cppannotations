#ifndef _INCLUDED_PARENTPROCESS_H_
#define _INCLUDED_PARENTPROCESS_H_

#ifndef _INCLUDED_IOSFWD_
#include <iosfwd>
#define _INCLUDED_IOSFWD_
#endif

namespace FBB
{
    class ParentProcess
    {
        public:
            virtual ~ParentProcess()
            {}

            virtual void run        // pure virtual function: implement in
            (                       // derived classes
                int pid,
                std::istream &readChildCout,
                std::istream &readChildCerr,
                std::ostream &writeChildCin
            ) = 0;
    };
}

#endif
