#include "main.ih"

int main()
try
{
    std::error_code ec = CalculatorError::TypeError;
//    assert(ec == ErrorSource::CalcError);
//    assert(ec != ErrorSource::SimError);
//    assert(ec != ErrorSource::InputError);
//
    ec = CalculatorError::ArityError;
    std::cout << ec << ' ' << ec.message() << '\n';
    throw std::system_error{ ec, "For demonstration purposes: " };
}
catch (std::system_error &se)
{
    std::cout << se.what() << ": " << se.code() << '\n';
}

