#include "../htmlindex.h"

bool IndexEntry::operator<(IndexEntry const &other) const
{
    if (isalnum(uppercaseKey[0]) && !isalnum(other.uppercaseKey[0]))
        return false;           // alphanumeric entries after special chars

    if (!isalnum(uppercaseKey[0]) && isalnum(other.uppercaseKey[0]))
        return true;            // special chars before alphanumeric entries

    return uppercaseKey < other.uppercaseKey;
}
