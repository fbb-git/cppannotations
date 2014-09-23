#include "tabber.ih"

void Tabber::run()
{
    d_column = 0;

    if (g_entab)
        entab();
    else
        detab();
}
