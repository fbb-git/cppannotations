#include "parser.ih"

void Parser::display(int x)
{
    cerr << "RPN: " << d_rpn.str() << endl;
    cerr << "int: " << x << endl;
    d_rpn.str(string());
}
