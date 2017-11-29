#include "calculatorcategory.ih"

//impl
std::string CalculatorCategory::message(int ce) const
{
    auto iter = s_errors.find(static_cast<CalculatorError>(ce));

    return iter == s_errors.end() ?
                "CalculatorError not recognized"
            :
                std::get<0>(iter->second);
}
//=
