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
        static CalculatorCategory &instance();

        bool equivalent(std::error_code const &ec, int condNr) const noexcept 
                                                                    override;
        char const *name() const noexcept override;
        std::string message(int ce) const override;

    private:
        CalculatorCategory() = default;
};
//=

std::error_code make_error_code(CalculatorError ce);


#endif


