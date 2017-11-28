#include "errorcondition.ih"

ErrorCondition::ErrorCondition()
:
    d_conditionInfo(1, { "", "(Condition not defined)" })   // avoid 0 numbers
{}
