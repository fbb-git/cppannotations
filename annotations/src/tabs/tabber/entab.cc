#include "tabber.ih"

void Tabber::entab()
{
    char ch;
    while (d_in.get(ch))
    {
        ++d_column;

        switch (ch)
        {
            case ' ':
                space();
            break;

            case '\t':
                tab();
            break;

            case '\n':
                newline();
            break;

            default:
                otherChar();
            break;
        }
    }
}
