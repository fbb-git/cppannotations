#ifndef INCLUDED_CATMAP_
#define INCLUDED_CATMAP_

#include <unordered_map>
#include <tuple>

//impl
template <class Enum>
class CatMap: public std::unordered_map<
                            Enum, 
                            std::tuple<char const *, char const *>
                    >       //         description   condition name
{
    typedef std::tuple<char const *, char const *> Tuple;
    typedef std::unordered_map<Enum, Tuple> Map;

    public:
        CatMap(std::initializer_list<typename Map::value_type> const &list);
};

template <class Enum>
CatMap<Enum>::CatMap(
                std::initializer_list<typename Map::value_type> const &list)
:
    Map{ list }
{}
//=

#endif




