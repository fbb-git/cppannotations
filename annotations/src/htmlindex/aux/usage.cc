#include "../htmlindex.h"

void usage(string const &basename)
{
    cout << "\n" <<
    basename << " by Frank B. Brokken (f.b.brokken@rug.nl)\n"
    "\n"
    "C++ Annotations html index page builder, V. " << version << endl <<
    "Copyright (c) 2001-2006 Frank B. Brokken. GPL.\n"
    "\n"
    "Usage: " << basename << " < indexpage > outputpage\n"
    "Where:\n"
    "   indexpage: file containing `<index nr key>' index entries\n"
    "   outputpage: file to write the index page to (e.g., "
                                                    "cplusplusidx.html)\n" <<
    endl;

    exit(1);
}
