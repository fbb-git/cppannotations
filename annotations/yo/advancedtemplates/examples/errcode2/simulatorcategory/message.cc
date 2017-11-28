#include "simulatorcategory.ih"

std::string SimulatorCategory::message(int ce) const
{
    auto iter = s_errors.find(static_cast<SimulatorError>(ce));

    return iter == s_errors.end() ?
                "SimulatorError not recognized"
            :
                std::get<0>(iter->second);
}

