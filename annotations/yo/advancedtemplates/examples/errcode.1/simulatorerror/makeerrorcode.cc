#include "simulatorerror.ih"

std::error_code make_error_code(SimulatorError ce)
{
    return { static_cast<int>(ce), simulatorCategory };
}



