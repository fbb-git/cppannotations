#ifndef INCLUDED_CINREDIRECTOR_H_
#define INCLUDED_CINREDIRECTOR_H_


#ifndef INCLUDED_REDIRECTOR_H_
#include "../redirector/redirector.h"
#endif

#ifndef INCLUDED_OPIPE_H_
#include "../opipe/opipe.h"
#endif

namespace FBB
{
    class CinRedirector: public Redirector
    {
        private:
            OPipe d_cinPipe;

        public:
            virtual void childRedirections();
            virtual void parentRedirections();

            virtual std::ostream &writeChildCin()
            {
                return d_cinPipe;
            }
    };
}

#endif
