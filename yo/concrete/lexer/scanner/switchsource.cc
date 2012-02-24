#include "scanner.ih"

void Scanner::switchSource()
{
    pushStream(d_nextSource);
    begin(StartCondition__::INITIAL);
}
