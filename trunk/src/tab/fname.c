#include <string.h>

#ifdef MSDOS
#define SEP '\\'
#else
#define SEP '/'
#endif

char *fname(char *prog)
{
    register char
	*cp;

    if ( (cp = strrchr(prog, SEP)) )
	cp++;
    else
	cp = prog;

#   ifdef MSDOS
    *strstr (cp, ".EXE") = '\0';
#   endif

    return (cp);
}
