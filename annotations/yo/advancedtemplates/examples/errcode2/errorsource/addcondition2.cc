#include "errorsource.ih"

void ErrorSource::addCondition(char const *name)
{
    if (d_condition.find(name) != d_condition.end())
        throw std::logic_error(
                    name + std::string{ " condition already defined" });

    d_condition[name] = d_info.size();
}
