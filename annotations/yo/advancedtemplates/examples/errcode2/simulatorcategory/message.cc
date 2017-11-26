#include "simulatorcategory.ih"

namespace
{
    std::unordered_map<SimulatorError, char const *> s_errors =
    {
        { SimulatorError::EngineFailure,    "Engine malfunction"        },
        { SimulatorError::ComFailure,       "Com failure"               },
        { SimulatorError::RangeError,       "Beacon out of range"       },
        { SimulatorError::UnknownFunction,  "AP function not available" },
    };
}

std::string SimulatorCategory::message(int ce) const
{
    auto iter = s_errors.find(static_cast<SimulatorError>(ce));

    return iter == s_errors.end() ?
                "SimulatorError not recognized"
            :
                iter->second;
}

