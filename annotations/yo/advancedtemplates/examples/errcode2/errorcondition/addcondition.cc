#include "errorcondition.ih"

void ErrorCondition::addCondition(
            char const *name, char const *description)
{
    if (d_condition.find(name) != d_condition.end())
        throw std::logic_error(
                    name + std::string{ " condition already defined" });

    d_condition.insert(
                    ConditionMap::value_type{name, d_conditionInfo.size()}
                );

    d_conditionInfo.push_back({ name, description });
}

