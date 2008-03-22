#include "table.h"

#ifndef SYSINC_STRING_
#include <string>
#define SYSINC_STRING_
#endif

using namespace std;
using namespace FBB;

int main()
{
    TableSupport ts;
    string s;

    Table<string::iterator>
        tab
        (
            s.begin(),
            s.end(),
            ts,
            3,
            TableBase::Horizontal
        );

}
