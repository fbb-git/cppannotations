#ifndef INCLUDED_CALCULATORERROR_
#define INCLUDED_CALCULATORERROR_

#include <system_error>

//calcerrc
enum class CalculatorError
{
    // no 0, since that's by convention implies no error
    //  values do not have to be consecutive
    NoLvalue = 1,           // lhs of assignment is lvalue
    TypeError,              // incorrect expression type
    RangeError,             // e.g. sqrt(-1)
    ArityError,             // too few, too many arguments to a function
    UnknownFunction,        // function not defined
    MissingParentheses,     // ( and ) don't match
};
//=

class CalculatorCategory: public std::error_category
{
    char const *name() const noexcept override;
    std::string message(int ce) const override;
};

extern CalculatorCategory const calculatorCategory;

std::error_code make_error_code(CalculatorError ce);

//calctrait
namespace std
{
    template <>
    struct is_error_code_enum<CalculatorError>: public true_type 
    {};
}

//=

#endif
