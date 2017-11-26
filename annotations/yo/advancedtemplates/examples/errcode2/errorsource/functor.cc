#include "errorsource.ih"

ErrorSource::Enum ErrorSource::operator()(char const *conditionName) const
{
    auto iter = d_condition.find(conditionName);

    return iter == d_condition.end() ? 
                    Enum{} 
                :                   // return the vector index as Enum
                    static_cast<Enum>(iter->second);
}
