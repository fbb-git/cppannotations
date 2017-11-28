#include "main.ih"

            // define globally available error conditions
            // (may also be defined elsewhere, e.g., by 3rd parties
            //

int main()
try
{
    ErrorCondition &errorCond  = ErrorCondition::instance();
    std::cerr << errorCond.name() << '\n';

    std::cerr << CalculatorCategory::instance().name() << '\n';
    std::cerr << SimulatorCategory::instance().name() << '\n';
    
    errorCond.addCondition("InputCond",   "error in user request");
    errorCond.addCondition("UnavailCond", "function not available");
    errorCond.addCondition("SystemCond",  "system failure");

        // ec is an actual error code, belonging to some error enum
        // the assert checks whether the specified error code belongs to
        // the specified error condition

//                    // also OK: ErrorCondition::Enum{};
//    std::error_condition cond = errorCond("InputCond"); 

    std::error_code ec = CalculatorError::TypeError;
    assert(ec != ErrorCondition::Enum{});
    assert(ec == errorCond("UnavailCond"));
    assert(ec != errorCond("SystemCond"));

    ec = CalculatorError::MissingParentheses;
    assert(ec == errorCond("InputCond"));

    ec = CalculatorError::ArityError;
    std::cout << ec << ' ' << ec.message() << '\n';
    throw std::system_error{ ec, "For demonstration purposes: " };
}
catch (std::system_error const &se)
{
    std::cout << "System Error: " << se.what() << ": " << se.code() << '\n';

    //throw;    cannot be rethrown!!

}
catch (std::exception const &exc)
{
    std::cout << "Exception: " << exc.what() << '\n';
}
