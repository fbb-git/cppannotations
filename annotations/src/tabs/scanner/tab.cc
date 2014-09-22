#include "scanner.ih"

void Scanner::tab()
{
    if (g_entab)
    {
        processSpaces();
        out().put('\t');
    }
    else
    {
        do
            out().put(' ');
        while (++d_column % g_tabPos != 0);
    }

    d_column = 0;                     // as we are at a tab-position 
}
