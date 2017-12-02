#include "simulatorcategory.ih"

std::string SimulatorCategory::message(int ce) const
{
    return CategoryBase<SimulatorError>::message(
                    ce, "SimulatorError not recognized");
}
