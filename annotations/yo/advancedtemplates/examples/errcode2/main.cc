#include "main.ih"

            // define globally available error conditions
char const *g_InputError = "InputError";

int main()
try
{
    g_errorSource.addCondition(g_InputError,  "error in user request");

    std::cerr << "Calculator cat = " << 
    static_cast<std::error_category const &>(g_calculatorCategory).name() << 
    '\n';

    g_errorSource.addCategory(g_calculatorCategory);
    g_errorSource.addCategory(g_simulatorCategory);

        // ec is an actual error code, belonging to some error enum
        // the assert matches if the test for that particuler error code
        // succeeds.

        
    std::error_code ec = CalculatorError::TypeError;
    assert(ec == g_errorSource(g_calculatorCategory.id()));
    assert(ec != g_errorSource(g_simulatorCategory.id()));

    ec = CalculatorError::MissingParentheses;
    assert(ec == g_errorSource(g_InputError));

    ec = CalculatorError::ArityError;
    std::cout << ec << ' ' << ec.message() << '\n';
    throw std::system_error{ ec, "For demonstration purposes: " };
}
catch (std::system_error &se)
{
    std::cout << se.what() << ": " << se.code() << '\n';
}


