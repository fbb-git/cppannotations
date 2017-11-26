#ifndef INCLUDED_CALCULATORCATEGORY_
#define INCLUDED_CALCULATORCATEGORY_

#include "../categorydata/categorydata.h"

//class
enum class CalculatorError;

class CalculatorCategory: public CategoryData
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
    return d_id;
}

extern CalculatorCategory const g_calculatorCategory;

std::error_code make_error_code(CalculatorError ce);


#endif


