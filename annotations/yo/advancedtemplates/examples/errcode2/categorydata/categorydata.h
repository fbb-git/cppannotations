#ifndef INCLUDED_CATEGORYDATA_
#define INCLUDED_CATEGORYDATA_

#include <system_error>

//class
struct CategoryData: public std::error_category
{
    char const *d_id;
    char const *d_description;
    bool (*const d_equivalent)
                (char const *conditionName, std::error_code const &ec);
    std::error_category const &d_singleton;

    CategoryData(char const *id, char const *description,
                 bool (*const equivalent)
                           (char const *conditionName, 
                            std::error_code const &ec),
                  std::error_category const &singleton);
};
//=
#endif
