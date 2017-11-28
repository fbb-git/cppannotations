#ifndef INCLUDED_CATEGORYDATA_
#define INCLUDED_CATEGORYDATA_

#include <system_error>
#include <unordered_map>
#include <tuple>

//class
struct CategoryData: public std::error_category
{
//    char const *d_description;
//    bool (*const d_equivalent)
//                (char const *conditionName, std::error_code const &ec);
//    std::error_category const &d_singleton;
//
//    CategoryData(char const *id, char const *description,
//                 bool (*const equivalent)
//                           (char const *conditionName, 
//                            std::error_code const &ec),
//                  std::error_category const &singleton);
};
//=

template <class Enum>
class CatMap: public std::unordered_map<Enum, 
                                        std::tuple<char const *, char const *>>
                                        //         description   condition name
{
    typedef std::tuple<char const *, char const *> Tuple;
    typedef std::unordered_map<Enum, Tuple> Map;

    public:
        CatMap(std::initializer_list<typename Map::value_type> const &list);
};

template <class Enum>
CatMap<Enum>::CatMap(std::initializer_list<typename Map::value_type> const &list)
:
    Map{ list }
{}

#endif
