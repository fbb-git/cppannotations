#ifndef Parser_h_included
#define Parser_h_included

#include <iostream>
#include <sstream>
#include <bobcat/a2x.h>

#include "parserbase.h"
#include "../scanner/scanner.h"


#undef Parser
class Parser: public ParserBase
{
    std::ostringstream d_rpn;
    // $insert scannerobject
    Scanner d_scanner;

    public:
        int parse();

    private:

        void display(int x);
        void display(double x);
        void done() const;

        static double d(int i)
        {
            return i;
        }

        template <typename Type>
        Type exec(char c, Type left, Type right)
        {
            d_rpn << " " << c << " ";
            return c == '*' ? left * right : left + right;
        }

        template <typename Type>
        Type neg(Type op)
        {
            d_rpn << " n ";
            return -op;
        }

        template <typename Type>
        Type convert()
        {
            Type ret = FBB::A2x(d_scanner.YYText());
            d_rpn << " " << ret << " ";
            return ret;
        }

        void reset();

        void error(char const *msg)
        {
            std::cerr << msg << std::endl;
        }

        int lex()
        {
            return d_scanner.yylex();
        }

        void print()
        {}

    // support functions for parse():

        void executeAction(int d_production);
        unsigned errorRecovery();
        int lookup(int token);
        int nextToken();
};


#endif
