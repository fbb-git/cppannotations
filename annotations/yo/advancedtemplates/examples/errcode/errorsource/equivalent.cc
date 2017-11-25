#include "errorsource.ih"

namespace
{
        // EXTREMELY UGLY: IF A NEW ERROR TYPE IS ADDED WE, RATHER THAN THE
        // NEW TYPE DETERMINES THE CATEGORY, AND ALSO: THIS CLASS MUST BE
        // MODIFIED 

        // THE OTHER WAY AROUND DOESN'T WORK EITHER? LET'S ESCALATE
        // ErrorSource... 

    bool calcError(std::error_code const &ec)
    {
        return ec != CalculatorError::MissingParentheses;
    };

    bool inputError(std::error_code const &ec)
    {
        return ec == CalculatorError::MissingParentheses;
    };

    bool simError(std::error_code const &ec)
    {
        return ec.category() == simulatorCategory;
    };


        // A FACILITY FOR ADDING NEW SOURCES TO THIS MAP SHOULD BE PROVIDED.

    typedef bool (*EquivPtr)(std::error_code const &);

    std::unordered_map<ErrorSource, EquivPtr> s_equivalent =
    {
        { ErrorSource::CalcError,  calcError     },
        { ErrorSource::InputError, inputError    },
        { ErrorSource::SimError,   simError      }
    };

}

bool ErrorCategory::equivalent(
                        std::error_code const &code, int condition
                    ) const noexcept
{
    auto iter = s_equivalent.find(static_cast<ErrorSource>(condition));
    return iter == s_equivalent.end() ? false : (*iter->second)(code);
}

