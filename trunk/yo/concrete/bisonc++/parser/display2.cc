#include "parser.ih"

void Parser::display(double x)
{
    cerr << "RPN: " << d_rpn.str() << endl;
    cerr << "double: " << x << endl;
    d_rpn.str(string());
}
