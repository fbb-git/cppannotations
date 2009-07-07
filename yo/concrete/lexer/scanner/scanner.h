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
    struct FileInfo
    {
        std::string d_name;
        std::ifstream    *d_in;
        
        FileInfo(std::string name)
        :
            d_name(name),
            d_in(new std::ifstream(name.c_str()))
        {}
        FileInfo(std::string name, bool)
        :
            d_name(name),
            d_in(0)
        {}
//        inline bool operator==(FileInfo const &rhs) const
//        {
//            return d_name == rhs.d_name;
//        }
    };

    friend bool operator==(FileInfo const &fi, std::string const &name);

    std::stack<yy_buffer_state *>   d_state;
    std::vector<FileInfo>           d_fileInfo;
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
    return d_fileInfo.back().d_name;
}
//=

#endif
