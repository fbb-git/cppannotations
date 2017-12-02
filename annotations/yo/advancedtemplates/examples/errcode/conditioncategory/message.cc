#include "conditioncategory.ih"

std::string ConditionCategory::message(int ce) const
{
    return
        std::get<1>(
            d_conditionInfo[
                static_cast<size_t>(ce) >= d_conditionInfo.size() ? 0 : ce
            ]
        );
}
