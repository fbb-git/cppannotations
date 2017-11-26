#include "simulatorcategory.ih"

SimulatorCategory::SimulatorCategory()
:
    CategoryData {
        "SimError",
        "simulator: failure", 
        equivalent,
        *this
    }
{
    if (this != &g_simulatorCategory)
        throw std::logic_error("SimulatorCategory object already defined");
}
