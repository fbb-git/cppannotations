#include "../htmlindex.h"

IndexEntry::IndexEntry(string const &keystring,
                        unsigned filenameIndex, unsigned labelNr)
:
    key(keystring)
{
    for (string::iterator it = key.begin(); it != key.end(); it++)
        if (*it != ' ')
            uppercaseKey += toupper(*it);

    labels.push_back(pair<unsigned, unsigned>(filenameIndex, labelNr));
}
    

