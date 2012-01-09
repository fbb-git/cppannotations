#ifndef SCANNER_H_
#define SCANNER_H_

#include "../semantic/semantic.h"

#if ! defined(SKIP_FLEXLEXER_) && ! defined(SYSINC_FLEXLEXER_H_)
#include <FlexLexer.h>
#define SYSINC_FLEXLEXER_H_
#endif

class Scanner: public yyFlexLexer
{
    Semantic *d_semval;     // received fm the parser

    public:
        Scanner(Semantic *semval);
        int yylex();
};

inline Scanner::Scanner(Semantic *semval)
:
    d_semval(semval)
{}

#endif
