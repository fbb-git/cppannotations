#ifndef INCLUDED_CALCULATORCATEGORY_
#define INCLUDED_CALCULATORCATEGORY_

#include <system_error>

#include "../categorydata/categorydata.h"

//class
enum class CalculatorError;

class CalculatorCategory: public std::error_category, public CategoryData
{
    public:
        CalculatorCategory();           // enforces the singleton 

        char const *id() const;

        static bool equivalent(char const *conditionName, 
                               std::error_code const &ec);

    private:
        char const *name() const noexcept override;
        std::string message(int ce) const override;
};
//=

inline char const *CalculatorCategory::id() const
{
    return CategoryData::id;
}

extern CalculatorCategory const g_calculatorCategory;
// extern char const *g_CalcError;

std::error_code make_error_code(CalculatorError ce);


#endif


