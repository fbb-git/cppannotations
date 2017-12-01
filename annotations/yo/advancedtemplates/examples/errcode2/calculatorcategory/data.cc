#include "calculatorcategory.ih"

CalculatorCategory *CalculatorCategory::s_instance;

                                    // defines descriptions and cond. names
//=impl
template <>
CatMap<CalculatorError> const CategoryBase<CalculatorError>::s_errors = 
{
    { CalculatorError::NoLvalue, 
            {"lhs of assignment is not a variable", "UnavailCond" } },
    { CalculatorError::TypeError, 
            {"type of expression incorrect",        "UnavailCond" } },
    { CalculatorError::RangeError, 
            {"argument value not allowed",          "UnavailCond" } },
    { CalculatorError::ArityError, 
                {"incorrect number of arguments",   "UnavailCond" } },
    { CalculatorError::UnknownFunction, 
            {"function not defined",                "UnavailCond" } },
    { CalculatorError::MissingParentheses, 
            {"parentheses don't match",             "InputCond"   } },
};
//=
