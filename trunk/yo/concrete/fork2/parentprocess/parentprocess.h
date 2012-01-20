#ifndef INCLUDED_PARENTPROCESS_H_
#define INCLUDED_PARENTPROCESS_H_

#ifndef INCLUDED_IOSFWD_
#include <iosfwd>
#define INCLUDED_IOSFWD_
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
