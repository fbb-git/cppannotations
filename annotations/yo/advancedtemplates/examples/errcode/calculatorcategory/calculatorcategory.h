#ifndef INCLUDED_CALCULATORCATEGORY_
#define INCLUDED_CALCULATORCATEGORY_

#include "../categorybase/categorybase.h"

enum class CalculatorError;

//class
class CalculatorCategory: public CategoryBase<CalculatorError>
{
    static CalculatorCategory *s_instance;

    public:
        static CalculatorCategory &instance();

        char const *name() const noexcept override;
        std::string message(int ce) const override;

    private:
        CalculatorCategory() = default;
};
//=

std::error_code make_error_code(CalculatorError ce);


#endif
