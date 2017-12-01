#include "simulatorcategory.ih"

std::string SimulatorCategory::message(int ce) const
{
    return CatMessage<SimulatorError>::message(
                    ce, "SimulatorError not recognized");
}

