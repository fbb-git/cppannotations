#include "errorcondition.ih"

size_t ErrorCondition::nr(char const *condName) const
{
    auto iter = d_condition.find(condName);
    
    return iter == d_condition.end() ? 0 : iter->second;
}
