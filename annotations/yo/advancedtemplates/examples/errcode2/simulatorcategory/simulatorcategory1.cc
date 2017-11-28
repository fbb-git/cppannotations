#include "simulatorcategory.ih"

SimulatorCategory::SimulatorCategory()
{
    ErrorCondition::instance().addCategory(
                            "SimulatorCategory", this, equivalent);
}
