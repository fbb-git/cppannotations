#ifndef INCLUDED_CALCULATORCATEGORY_
#define INCLUDED_CALCULATORCATEGORY_

#include <system_error>
#include "../catmap/catmap.h"

enum class CalculatorError;

//class
class CalculatorCategory: public std::error_category
{
    static CalculatorCategory *s_instance;

    static CatMap<CalculatorError> s_errors;

    public:
        static bool equivalent(size_t condNr, std::error_code const &ec);
        static CalculatorCategory &instance();

        char const *name() const noexcept override;
        std::string message(int ce) const override;

    private:
        CalculatorCategory();
};
//=

std::error_code make_error_code(CalculatorError ce);


#endif


