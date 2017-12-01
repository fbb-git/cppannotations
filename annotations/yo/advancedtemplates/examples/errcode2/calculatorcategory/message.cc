#include "calculatorcategory.ih"

//impl
std::string CalculatorCategory::message(int ev) const
{
    return CategoryBase<CalculatorError>::message(
                    ev, "CalculatorError not recognized");
}
//=
