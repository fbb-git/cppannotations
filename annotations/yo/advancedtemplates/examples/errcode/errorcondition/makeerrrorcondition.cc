#include "errorcondition.ih"

std::error_condition make_error_condition(ErrorCondition::Enum ec)
{
    return { static_cast<int>(ec), ConditionCategory::instance() };
}
