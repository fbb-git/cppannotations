#include "calculatorcategory.ih"

CalculatorCategory &CalculatorCategory::instance()
{
    if (s_instance == 0)
        s_instance = new CalculatorCategory;

    return *s_instance;
}
