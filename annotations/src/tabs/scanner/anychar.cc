#include "scanner.ih"

void Scanner::anyChar()
{
    if (g_entab)
        processSpaces();
    ++d_column;
    out().put(matched()[0]);
}
