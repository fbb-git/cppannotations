#include <iostream>
#include <string>
#include <unordered_map>
#include <tuple>
#include <system_error>

using namespace std;

    enum class CalculatorErrc
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

namespace std
{
    template <>
    struct is_error_code_enum<CalculatorErrc>: public true_type 
    {};
}

namespace 
{
    unordered_map<CalculatorErrc, char const *> s_errors =
    {
        { CalculatorErrc::NoLvalue, "lhs of assignment is not a variable" },
        { CalculatorErrc::TypeError, "type of expression incorrect"       },
        { CalculatorErrc::RangeError, "argument value not allowed"        },
        { CalculatorErrc::ArityError, "incorrect number of arguments"     },
        { CalculatorErrc::UnknownFunction, "function not defined"         },
        { CalculatorErrc::MissingParentheses, "parentheses don't match"   },
    };

    struct CalculatorErrCategory: public std::error_category
    {
        char const *name() const noexcept override;
        std::string message(int ce) const override;
    };
    
    char const *CalculatorErrCategory::name() const noexcept
    {
        return "calculator";
    }
    
    string CalculatorErrCategory::message(int ce) const
    {
        auto iter = s_errors.find(static_cast<CalculatorErrc>(ce));

        return iter == s_errors.end() ?
                    "CalculatorErrc not recognized"
                :
                    iter->second;
    }

                                    // define the singleton
    CalculatorErrCategory const calculatorErrCategory;

}   // anon. namespace
    
error_code make_error_code(CalculatorErrc ce)
{
    return { static_cast<int>(ce), calculatorErrCategory };
}

int main()
try
{
    error_code ec = CalculatorErrc::ArityError;
    cout << ec << ' ' << ec.message() << '\n';
    throw system_error{ ec, "For demonstration purposes: " };
}
catch (system_error &se)
{
    cout << se.what() << ": " << se.code() << '\n';
}




