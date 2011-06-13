#ifndef SCANNER_H_
#define SCANNER_H_

#if ! defined(SKIP_FLEXLEXER_)
#include <FlexLexer.h>
#endif

class Scanner: public yyFlexLexer
{
    public:
        int yylex();
};

#endif
