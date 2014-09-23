#include "tabber.ih"

// d_column is the # of characters so far in the actual field of g_tabWidth
// characters.

void Tabber::detab()
{
    char ch;

    while (d_in.get(ch))
    {
        switch (ch)
        {
            case '\n':
                d_column = 0;       // no characters in the current field,
                                    // since after this we're on the next line
            break;

            case '\t':
                d_out << setw(g_tabWidth - d_column) << ' ';
                d_column = 0;       // no chars in the current field, as we
                                    // just filled it up by blanks

            continue;               // process the next character

            default:
                d_column = (d_column + 1) % g_tabWidth;
            break;
        }
        d_out.put(ch);  // write ordinary char. 
    }
}

