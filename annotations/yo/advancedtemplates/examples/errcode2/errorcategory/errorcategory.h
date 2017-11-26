#ifndef INCLUDED_ERRORCATEGORY_H_
#define INCLUDED_ERRORCATEGORY_H_

#include <system_error>
#include "../errorsource/errorsource.h"

struct ErrorCategory: public std::error_category
{
//    typedef std::unordered_map<ErrorSource, Info> Map;

    public:
        ErrorCategory();            // enforces the singleton

    private:
        char const *name() const noexcept override;
        std::string message(int ce) const override;
    
        bool equivalent(std::error_code const &code, int condition) 
                                            const noexcept override;
};

//simcondtrait
namespace std
{
    template <>
    struct is_error_condition_enum<ErrorSource::Enum>: public true_type 
    {};
}
//=

std::error_condition make_error_condition(ErrorSource::Enum es);

extern ErrorCategory const g_errorCategory;




#endif
