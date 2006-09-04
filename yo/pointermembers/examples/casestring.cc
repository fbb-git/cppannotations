#include "casestring.h"

string caseString::*caseString::stringMember[] =
{
    &caseString::original,
    &caseString::lower,
    &caseString::upper,
};

int main()
{
    caseString
        hello("Hello World");

    cout << hello << endl;
    hello.setMode(caseString::LOWER);
    cout << hello << endl;
    hello.setMode(caseString::UPPER);
    cout << hello << endl;
    hello.setMode(caseString::ORIGINAL);
    cout << hello << endl;
}
