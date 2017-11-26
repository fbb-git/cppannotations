#include "calculatorcategory.ih"

//ctor
CalculatorCategory::CalculatorCategory()
:
    CategoryData {
        "CalcError",
        "calculator: cannot compute", 
        equivalent,
        *this
    }
{
    if (this != &g_calculatorCategory)
        throw std::logic_error("CalculatorCategory object already defined");
}
//=
