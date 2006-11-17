#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <vector>


namespace // anonymous
{
    struct PI;
}


class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
    enum Tokens
    {
        INT = 257,
        DOUBLE,
        UnaryMinus,
    };

// $insert STYPE
struct STYPE
{
    int i;
    double d;
};


    private:
        int d_stackIdx;
        std::vector<size_t>   d_stateStack;
        std::vector<STYPE>    d_valueStack;

    protected:
        enum Return
        {
            PARSE_ACCEPT = 0,   // values used as parse()'s return values
            PARSE_ABORT  = 1
        };
        enum ErrorRecovery
        {
            DEFAULT_RECOVERY_MODE,
            UNEXPECTED_TOKEN,
        };
        bool        d_debug;
        size_t    d_nErrors;
        int         d_token;
        int         d_nextToken;
        size_t    d_state;
        STYPE      *d_vsp;
        STYPE       d_val;

        ParserBase();

        void ABORT() const throw(Return);
        void ACCEPT() const throw(Return);
        void ERROR() const throw(ErrorRecovery);
        void clearin();
        bool debug() const;
        void pop(size_t count = 1);
        void push(size_t nextState);
        size_t reduce(PI const &productionInfo);
        void setDebug(bool mode);
        size_t top() const;
}; 

inline bool ParserBase::debug() const
{
    return d_debug;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug = mode;
}

// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


