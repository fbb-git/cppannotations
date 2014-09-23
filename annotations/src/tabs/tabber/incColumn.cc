#include "tabber.ih"

bool Tabber::tabColumn()
{
    return ++d_column % g_tabWidth == 0;
}
