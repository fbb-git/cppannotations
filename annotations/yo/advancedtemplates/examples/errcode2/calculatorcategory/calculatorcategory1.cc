#include "calculatorcategory.ih"

CalculatorCategory::CalculatorCategory()
{
    if (this != &g_calculatorCategory)
        throw std::logic_error("CalculatorCategory object already defined");
}
