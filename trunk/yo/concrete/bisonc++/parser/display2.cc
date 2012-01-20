#include "parser.ih"

void Parser::display(double x)
{
    cerr << "RPN: " << d_rpn.str() << '\n';
    cerr << "double: " << x << '\n';
    d_rpn.str(string());
}
