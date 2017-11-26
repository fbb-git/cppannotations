#include "calculatorerror.ih"

bool calcErrorEquivalent(char const *conditionName, 
                            std::error_code const &ec)
{
    // test for CalculatorError
    return 
            (ec != CalculatorError::MissingParentheses && 
                conditionName == g_CalcError)
            ||
            (ec == CalculatorError::MissingParentheses && 
                conditionName == g_InputError);
}
