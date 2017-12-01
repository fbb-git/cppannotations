#ifndef INCLUDED_CATMESSAGE_
#define INCLUDED_CATMESSAGE_

#include <system_error>
#include <string>

#include "../catmap/catmap.h"

template <class Enum>
class CatMessage: public std::error_category
{
    protected:
        static CatMap<Enum> const s_errors;

        std::string message(int ce, char const *noEnumValue) const;
};

template <class Enum>
std::string CatMessage<Enum>::message(int ce, char const *noEnumValue) const
{
    auto iter = s_errors.find(static_cast<Enum>(ce));

    return iter == s_errors.end() ?
                noEnumValue
            :
                std::get<0>(iter->second);
}

#endif




