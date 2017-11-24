#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <system_error>

using namespace std;

    enum class CalculatorErrc
    {
        // no 0, since that's by convention implies no error
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
    tuple<CalculatorErrc, char const *> s_errors[] =
    {
        { CalculatorErrc::NoLvalue, "lhs of assignment is not a variable" },
        { CalculatorErrc::TypeError, "type of expression incorrect"       },
        { CalculatorErrc::RangeError, "argument value not allowed"        },
        { CalculatorErrc::ArityError, "incorrect number of arguments"     },
        { CalculatorErrc::UnknownFunction, "function not defined"         },
        { CalculatorErrc::MissingParentheses, "parentheses don't match"   },
        { CalculatorErrc{}, "unrecognized CalculatorErrc"                 }
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
        CalculatorErrc code = static_cast<CalculatorErrc>(ce);
    
        get<0>(s_errors[size(s_errors) - 1]) = code;
    
        return get<1>(
                    *find_if(s_errors, s_errors + size(s_errors), 
                        [=](auto const &entry)
                        {
                            return code == get<0>(entry);
                        }
                    )
                );
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
    throw system_error{ ec, "Oops, something went wrong: " };
}
catch (system_error &se)
{
    cout << se.what() << ": " << se.code() << '\n';
}




