//                     version.cc

#include "main.ih"
#include "icmconf"

#ifdef USE_VERSION
#include "VERSION"
#endif

#ifndef AUTHOR
#define AUTHOR ""
#endif

#ifndef VERSION
#define VERSION "0.00.00"
#endif

#ifndef YEARS
#define YEARS "2012"
#endif

namespace Icmbuild
{
    char version[]  = VERSION;
    char years[]     = YEARS;
    
    char author[] = AUTHOR;
}
