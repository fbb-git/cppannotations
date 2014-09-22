#include "scanner.ih"

void Scanner::processSpaces()
{
    size_t nTabs;

    if (d_nSpaces >= g_minSpaces)
    {
        nTabs = d_column / g_tabPos - (d_column - d_nSpaces) / g_tabPos;
        if (nTabs > 0)
        {
            d_nSpaces = d_column % g_tabPos;
            for (; nTabs; nTabs--)
                out().put('\t');
        }
    }

    if (d_nSpaces != 0)
        out() << setw(d_nSpaces) << ' ';

    d_nSpaces = 0;
}

