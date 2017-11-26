#ifndef INCLUDED_CALCULATORCATEGORY_
#define INCLUDED_CALCULATORCATEGORY_

#include <system_error>

enum class CalculatorError;

class CalculatorCategory: public std::error_category
{
    public:
        CalculatorCategory();           // enforces the singleton 

    private:
        char const *name() const noexcept override;
        std::string message(int ce) const override;
};

extern CalculatorCategory const g_calculatorCategory;
extern char const *g_CalcError;

std::error_code make_error_code(CalculatorError ce);

bool calcErrorEquivalent(char const *conditionName, std::error_code const &ec);


#endif


