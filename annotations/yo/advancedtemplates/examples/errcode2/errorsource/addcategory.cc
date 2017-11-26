#include "errorsource.ih"

void ErrorSource::addCategory(
                        char const *name, 
                        char const *description,
                        std::error_category const &category,
                        EquivPtr ptr)
{
    addCondition(name);
    d_info.push_back({ name, description });
    d_category[category.name()] = ptr;
}
