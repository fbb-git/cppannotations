/*
    TAB.C 92 11 24
    Ported for Unix KK 94 04 06
    Port and maintenance for ELF: FBB 96/08/xx
    Skipping symbolic links: FBB 2001/07/22
    Repairing EOF swallow: FBB 2001/09/09
*/

#ifdef MSDOS
#if !defined(M_I86SM)
#error SMALL memory model expected
#endif
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MSDOS
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

extern int yylex (void);
extern char *fname (char *);

extern FILE
    *yyin,
    *yyout;

extern int
    column,
    nspaces;

int
    quiet = 0,
    entab = 0,
    minspaces = 4,
    tabpos = 8;

char
    version[] = "1.41",
    tempfile[] = "tab.tmp";


int main(int argc, char **argv)
{
    int
        piping = 0;
    char
        *progname;
    struct stat
        fileinfo;

    progname = fname(argv[0]);
    

    while (argc > 1 && *argv[1] == '-')
    {
        switch (argv[1][1])
        {
            case 'd':
                entab = 0;
                break;
            case 'e':
                entab = 1;
                break;
            case 's':
                if (!(minspaces = atoi(argv [1] + 2)))
                {
                    printf("%s: missing or illegal space count at -s, "
                            "assuming 4\n", progname);
                    minspaces = 4;
                }
                break;
            case 'c':
                if (!(tabpos = atoi(argv [1] + 2)))
                {
                    printf("%s: missing or illegal column count at -c, "
                           "assuming 8\n", progname);
                    tabpos = 8;
                }
                break;
            case 'q':
                    quiet = 1;
                break;
            default:
                if (!argv[1][1])
                {
                    piping = 1;
                    break;
                }
                printf("%s: unknown flag '-%c,' ignored\n",
                       progname, *(*argv + 1));
            break;
        }
        argv++;
        argc--;
    }

    if (argc == 1 && !piping)       /* error */
    {
        printf("\nTAB Entabber/Detabber V%s\n"
               "Copyright (c) GPL 1989-2006. All rights reserved.\n"
               "\n"
               "%s by Frank B. Brokken (f.b.brokken@rc.rug.nl).\n"
               "\n"
               "Usage: %s [-d | -e | -snnn | -cnnn]*  file(s)\n"
               "where:\n"
               "   -c  - entab at / detab to multiples of nnn columns "
                      "(default: 8)\n"
               "   -d  - tabs in file(s) are removed (detab)\n"
               "         (default action)\n"
               "   -e  - spaces in file(s) are changed into tabs (entab)\n"
               "   -q  - quiet: less output than otherwise\n"
               "   -s  - entab/detab a minimum number of nnn spaces "
                      "(default: 4)\n"
               "   file(s) - file(s) to entab/detab (are overwritten)\n"
               "             use - to filter stdin to stdout\n"
               "             non-regular files (e.g. symbolic links) are "
                                                                "skipped.\n"
               "\n"
               , version, progname, progname);
        return (1);
    }

    if (piping)
    {
        yyin = stdin;
        yyout = stdout;
        yylex();
        return (0);
    }

    for (++argv; *argv; ++argv)
    {
        if (lstat(*argv, &fileinfo))
        {
            printf("Can't stat %s: skipping\n", *argv);
            continue;
        }

        if (!S_ISREG(fileinfo.st_mode)) /* not a regular file   */
            continue;                   /* skip it silently     */

        if (!quiet)
            printf("processing %s\n", *argv);

        unlink(tempfile);

        if (rename(*argv, tempfile))
        {
            printf("%s: can't rename %s\n", progname, *argv);
            return (1);
        }

        if     
        (    
            !(yyin = fopen(tempfile, "r"))     
            ||
            !(yyout = fopen(*argv, "w"))    
        )
        {    
            printf ("%s: cannot open in- or output file\n", progname);    
            return (1);    
        }    

        yylex();    

        fclose (yyin);    
        fclose (yyout);    
    }

    unlink(tempfile);
    return (0);
}
