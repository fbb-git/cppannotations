#include "simulatorcategory.ih"

// static
bool SimulatorCategory::equivalent(std::error_code const &ec, int condNr)
                                                                const noexcept
{
    auto iter = s_errors.find(static_cast<SimulatorError>(ec.value()));

    return  iter != s_errors.end() 
            and
            std::get<1>(iter->second) == ErrorCondition::instance()[condNr];
}
