#include "calculatorerror.ih"

namespace
{
    std::unordered_map<CalculatorError, char const *> s_errors =
    {
        { CalculatorError::NoLvalue, "lhs of assignment is not a variable"  },
        { CalculatorError::TypeError, "type of expression incorrect"        },
        { CalculatorError::RangeError, "argument value not allowed"         },
        { CalculatorError::ArityError, "incorrect number of arguments"      },
        { CalculatorError::UnknownFunction, "function not defined"          },
        { CalculatorError::MissingParentheses, "parentheses don't match"    },
    };
}

std::string CalculatorCategory::message(int ce) const
{
    auto iter = s_errors.find(static_cast<CalculatorError>(ce));

    return iter == s_errors.end() ?
                "CalculatorError not recognized"
            :
                iter->second;
}
