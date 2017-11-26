#include "errorsource.ih"

void ErrorSource::addCategory(CategoryData const &data)
{
    addCondition(data.d_id);
    d_info.push_back({ data.d_id, data.d_description });
    d_category[data.d_singleton.name()] = data.d_equivalent;
}
