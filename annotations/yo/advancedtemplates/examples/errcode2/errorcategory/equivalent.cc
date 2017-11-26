#include "errorcategory.ih"

namespace
{
        // EXTREMELY UGLY: IF A NEW ERROR TYPE IS ADDED WE, RATHER THAN THE
        // NEW TYPE DETERMINES THE CATEGORY, AND ALSO: THIS CLASS MUST BE
        // MODIFIED 

        // THE OTHER WAY AROUND DOESN'T WORK EITHER? LET'S ESCALATE
        // ErrorSource... 

//    bool calcError(std::error_code const &ec)
//    {
//        return ec != CalculatorError::MissingParentheses;
//    };
//
//    bool inputError(std::error_code const &ec)
//    {
//        return ec == CalculatorError::MissingParentheses;
//    };
//
//    bool simError(std::error_code const &ec)
//    {
//        return ec.category() == simulatorCategory;
//    };
//
//
//        // A FACILITY FOR ADDING NEW SOURCES TO THIS MAP SHOULD BE PROVIDED.
//
//    
//
//    std::unordered_map<ErrorSource, EquivPtr> s_equivalent =
//    {
//        { ErrorSource::CalcError,  calcError     },
//        { ErrorSource::InputError, inputError    },
//        { ErrorSource::SimError,   simError      }
//    };
//
}

bool ErrorCategory::equivalent(
                        std::error_code const &code, int condition
                    ) const noexcept
{
    // code: bv een waarde uit calc.err.h. maar 't kan ook een heel andere
    // waarde zijn. Maar code.category geeft de bijbehorende category,
    // dwz. 'calculatorCategory'. Aangezien we weten welke category 't is,
    // kunnen we de error code doorgeven aan de equiv functie van de
    // desbetreffende class enum, die dan retourneert of de desbreffende code
    // een 'condition' code_condition is. De class weet dat, omdat de
    // beschikbare condities bij de constructie bekend zijn, aangezien
    // ErrorSource op dat moment al is geinitialiseerd.

    return g_errorSource.equivalent(condition, code);

//    auto iter = s_equivalent.find(static_cast<ErrorSource>(condition));
//
//    return iter == s_equivalent.end() ? false : (*iter->second)(code);
}



