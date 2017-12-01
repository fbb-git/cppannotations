#include "conditioncategory.ih"

// static
ConditionCategory &ConditionCategory::instance()
{
    if (s_instance == 0)
        s_instance = new ConditionCategory;

    return *s_instance;
}
