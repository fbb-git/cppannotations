#include "scanner.ih"

void Scanner::blank()
{
    ++d_column;
    ++d_nSpaces;

    if (not g_entab)
        out().put(' ');
}
