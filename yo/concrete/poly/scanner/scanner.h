#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "../semantic/semantic.h"

#if ! defined(_SKIP_YYFLEXLEXER_) && ! defined(_SYSINC_FLEXLEXER_H_)
#include <FlexLexer.h>
#define _SYSINC_FLEXLEXER_H_
#endif
    
class Scanner: public yyFlexLexer
{
    Semantic *d_semval;

    public:
        Scanner(Semantic *semval);
        int yylex();
};

inline Scanner::Scanner(Semantic *semval)
:
    d_semval(semval)
{}

#endif



