#include "simulatorcategory.ih"

SimulatorCategory &SimulatorCategory::instance()
{
    if (s_instance == 0)
        s_instance = new SimulatorCategory;

    return *s_instance;
}
