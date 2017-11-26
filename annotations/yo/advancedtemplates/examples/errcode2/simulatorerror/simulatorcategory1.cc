#include "simulatorerror.ih"

SimulatorCategory::SimulatorCategory()
{
    if (this != &g_simulatorCategory)
        throw std::logic_error("SimulatorCategory object already defined");
}
