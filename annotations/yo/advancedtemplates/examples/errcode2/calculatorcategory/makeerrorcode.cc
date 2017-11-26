#include "calculatorcategory.ih"

//makecalcerrc
std::error_code make_error_code(CalculatorError ce)
{
    return { static_cast<int>(ce), g_calculatorCategory };
}
//=

