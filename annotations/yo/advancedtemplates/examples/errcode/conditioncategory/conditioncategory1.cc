#include "conditioncategory.ih"

ConditionCategory::ConditionCategory()
:
    d_conditionInfo(1, { "", "(Condition not defined)" })   // avoid 0 numbers
{}
