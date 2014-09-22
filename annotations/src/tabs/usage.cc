//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << '\n' << 
        progname << " by " << Icmbuild::author << "\n" <<
        progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
        "Copyright (c) GPL " << Icmbuild::years << ". All rights reserved.\n"
        "\n"
        "Usage: %s [-d | -e | -snnn | -cnnn]*  file(s)\n"
        "Where:\n"
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
        "\n";
}
