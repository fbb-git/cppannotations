#ifndef _SCANNER_H_
#define _SCANNER_H_

#if ! defined(_SKIP_YYFLEXLEXER_)
#include <FlexLexer.h>
#endif

class Scanner: public yyFlexLexer
{
    public:
        int yylex();
};

#endif
