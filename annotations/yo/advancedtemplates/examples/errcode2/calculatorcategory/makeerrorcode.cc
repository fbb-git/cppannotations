#include "calculatorcategory.ih"

//make
std::error_code make_error_code(CalculatorError ce)
{
    return { static_cast<int>(ce), CalculatorCategory::instance() };
}
//=

