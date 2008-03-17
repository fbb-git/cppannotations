#ifndef INCLUDED_REDIRECTOR_H_
#define INCLUDED_REDIRECTOR_H_

#ifndef INCLUDED_IOSFWD_
#include <iosfwd>
#define INCLUDED_IOSFWD_
#endif

#ifndef INCLUDED_IOSTREAM_
#include <iostream>
#define INCLUDED_IOSTREAM_
#endif

namespace FBB
{
    class Redirector
    {
        public:
            enum
            {
                READ,
                WRITE
            };

            virtual ~Redirector()
            {}

            // sets up redirections in the child
            virtual void childRedirections()
            {}

            // sets up redirections in the parent
            virtual void parentRedirections()
            {}

            virtual std::ostream &writeChildCin()
            {
                return std::cout;
            }
            virtual std::istream &readChildCout()
            {
                return std::cin;
            }
            virtual std::istream &readChildCerr()
            {
                return std::cin;
            }
    };
}

#endif
