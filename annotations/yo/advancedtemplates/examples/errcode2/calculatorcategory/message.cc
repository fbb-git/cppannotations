#include "calculatorcategory.ih"

//impl
std::string CalculatorCategory::message(int ce) const
{
    return CatMessage<CalculatorError>::message(
                    ce, "CalculatorError not recognized");
}
//=
