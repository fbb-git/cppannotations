#include "tabber.ih"

void Tabber::entab()
{
    char ch;
    while (d_in.get(ch))
    {
        switch (ch)
        {
            case ' ':
                ++d_nSpaces;            // got a space
                if (tabColumn())        // we're at a tab column
                {
                    if (d_nSpaces < g_minSpaces)
                        outSpaces();
                    else
                    {
                        d_nSpaces = 0;
                        d_out.put('\t');
                    }
                }
            break;

            case '\n':
            case '\t':
                outSpaces();
                d_out.put(ch);
                d_column = 0;
            break;

            default:
                outSpaces();
                d_out.put(ch);
                ++d_column;
            break;
        }
    }
}
