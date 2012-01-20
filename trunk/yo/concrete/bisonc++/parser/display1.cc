#include "parser.ih"

void Parser::display(int x)
{
    cerr << "RPN: " << d_rpn.str() << '\n';
    cerr << "int: " << x << '\n';
    d_rpn.str(string());
}
