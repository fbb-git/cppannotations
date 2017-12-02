#ifndef INCLUDED_CATEGORYBASE_
#define INCLUDED_CATEGORYBASE_

#include <system_error>
#include <string>

#include "../catmap/catmap.h"

#include "../errorcondition/errorcondition.h"

//class
template <class Enum>
class CategoryBase: public std::error_category
{
    public:
        bool equivalent(std::error_code const &ec, int condNr) const noexcept
                                                                    override;

    protected:
        static CatMap<Enum> const s_errors;

        std::string message(int ev, char const *noEnumValue) const;
};
//=

//msg
template <class Enum>
std::string CategoryBase<Enum>::message(int ev, char const *noEnumValue) const
{
    auto iter = s_errors.find(static_cast<Enum>(ev));

    return iter == s_errors.end() ? noEnumValue : std::get<0>(iter->second);
}
//=


//equiv
template <class Enum>
bool CategoryBase<Enum>::equivalent(std::error_code const &ec, int condNr)
                                                                const noexcept
{
    auto iter = s_errors.find(static_cast<Enum>(ec.value()));

    return  iter != s_errors.end()
            and
            std::get<1>(iter->second) == ErrorCondition::instance()[condNr];
}
//=

#endif
