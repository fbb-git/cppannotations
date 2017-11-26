#include "errorsource.ih"

void ErrorSource::addCategory(CategoryData const &data)
{
    addCondition(data.id);
    d_info.push_back({ data.id, data.description });
    d_category[data.singleton.name()] = data.equivalent;
}
