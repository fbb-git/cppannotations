#ifndef INCLUDED_CATEGORYDATA_
#define INCLUDED_CATEGORYDATA_

#include <system_error>

struct CategoryData
{
    char const *id;
    char const *description;
    bool (*const equivalent)
                (char const *conditionName, std::error_code const &ec);
    std::error_category const &singleton;
};
        
#endif
