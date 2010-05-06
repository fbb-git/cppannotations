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

    cout << hello << '\n';
    hello.setMode(caseString::LOWER);
    cout << hello << '\n';
    hello.setMode(caseString::UPPER);
    cout << hello << '\n';
    hello.setMode(caseString::ORIGINAL);
    cout << hello << '\n';
}
