#include "errorcondition.ih"

void ErrorCondition::addCategory(char const *name,
                                 std::error_category const *singleton,
                                 EquivPtr function)
{
    if (d_category.find(singleton) != d_category.end())
        throw std::logic_error(
                    name + std::string{ " category already defined" });

    d_category.insert(
                    CategoryMap::value_type{ singleton, function }
                );
}
