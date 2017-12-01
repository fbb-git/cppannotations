#include "errorcondcat.ih"

ErrorCondCat::ErrorCondCat()
:
    d_conditionInfo(1, { "", "(Condition not defined)" })   // avoid 0 numbers
{}
