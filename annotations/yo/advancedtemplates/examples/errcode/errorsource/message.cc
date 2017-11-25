#include "errorsource.ih"

namespace 
{
    std::unordered_map<ErrorSource, char const *> s_errors =
    {
        { ErrorSource::CalcError,  "calculator: cannot compute"    },
        { ErrorSource::SimError,   "simulator: failure"            },
        { ErrorSource::InputError, "error in user request"         },
    };
}

std::string ErrorCategory::message(int ce) const
{
    auto iter = s_errors.find(static_cast<ErrorSource>(ce));

    return iter == s_errors.end() ?
                "Invalid Error Source Condition encountered"
            :
                iter->second;
}

