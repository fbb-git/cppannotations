#include <iostream>
#include <system_error>

#include "../calculatorerror/calculatorerror.h"
#include "../calculatorcategory/calculatorcategory.h"

int main()
try
{
    std::error_code ec = CalculatorError::ArityError;
    std::cout << ec << ' ' << ec.message() << '\n';
    throw std::system_error{ ec, "For demonstration purposes" };
}
catch (std::system_error &se)
{
    std::cout << se.what() << ":\n"
                "    " << se.code() << '\n';
}

/*
Outputs:
    calculator:4 incorrect number of arguments
    For demonstration purposes: incorrect number of arguments:
        calculator:4
*/
