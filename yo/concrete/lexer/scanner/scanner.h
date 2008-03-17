#ifndef SCANNER_H_
#define SCANNER_H_

#include <fstream>
#include <string>
#include <vector>
#include <stack>

//HEAD
#if ! defined(_SKIP_YYFLEXLEXER_)
#include <FlexLexer.h>
#endif

class Scanner: public yyFlexLexer
{
    std::stack<yy_buffer_state *>   d_state;
    std::vector<std::string>        d_fileName;
    std::string                     d_nextSource;

    static size_t const           s_maxDepth = 10;

    public:
        enum Error
        {
            invalidInclude,
            circularInclusion,
            nestingTooDeep,
            cantRead,
        };
//=

        Scanner(std::istream *yyin, std::string const &initialName);

        std::string const &lastFile();
        void stackTrace();  // dumps filename stack to cerr

        int yylex();

    private:
        Scanner(Scanner const &other);                  // NI
        Scanner &operator=(Scanner const &other);       // NI

        bool popSource(yy_buffer_state *current);       // true: source popped
        void pushSource(yy_buffer_state *current,       // switch to next
                            size_t bufferSize);
        void throwOnCircularInclusion();
};

//LAST
inline std::string const &Scanner::lastFile()
{
    return d_fileName.back();
}
//=

#endif
