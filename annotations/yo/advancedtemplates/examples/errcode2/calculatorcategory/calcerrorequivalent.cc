#include "calculatorcategory.ih"

// static
bool CalculatorCategory::equivalent(char const *conditionName, 
                                    std::error_code const &ec)
{
    // test for CalculatorError
    return 
            (ec != CalculatorError::MissingParentheses && 
                conditionName == g_calculatorCategory.id())
            ||
            (ec == CalculatorError::MissingParentheses && 
                conditionName == g_InputError);
}
