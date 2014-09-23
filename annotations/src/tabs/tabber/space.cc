#include "tabber.ih"

void Tabber::space()
{
    ++d_nSpaces;

    if (d_column % g_tabPos != 0)       // not at a tab-position
        return;

    if (d_nSpaces < g_minSpaces)        // to few spaces to write a tab
    {
        d_out << setw(d_nSpaces) << ' ';    // write blanks up to the tab-pos
        d_nSpaces = 0;
    }
    else                                // enough spaces to write a tab
    {
        d_nSpaces -= g_minSpaces;       // remove #spaces converted to \t
        d_out.put('\t');                
    }
}
