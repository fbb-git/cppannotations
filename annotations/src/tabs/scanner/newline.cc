#include "scanner.ih"

void Scanner::newline()
{
    out().put('\n');
    d_column = 0;
    d_nSpaces = 0;
}
