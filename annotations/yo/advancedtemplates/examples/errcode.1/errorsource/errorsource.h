#include <system_error>

//simerrsrc
enum class ErrorSource
{
    // no 0
    CalcError = 1,
    SimError,
    InputError
};
//=

class ErrorCategory: public std::error_category
{
    char const *name() const noexcept override;
    std::string message(int ce) const override;

    bool equivalent(std::error_code const &code, int condition)
                                            const noexcept override;
};

//simcondtrait
namespace std
{
    template <>
    struct is_error_condition_enum<ErrorSource>: public true_type
    {};
}
//=

std::error_condition make_error_condition(ErrorSource es);

extern ErrorCategory const errorCategory;
