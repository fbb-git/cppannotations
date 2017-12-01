#include "simulatorcategory.ih"

SimulatorCategory *SimulatorCategory::s_instance;

template<>
CatMap<SimulatorError> const CategoryBase<SimulatorError>::s_errors =
{
    { SimulatorError::EngineFailure,    
            { "Engine malfunction",         "SystemCond"  } },
    { SimulatorError::ComFailure,       
            { "Com failure",                "SystemCond"  } },
    { SimulatorError::RangeError,       
            { "Beacon out of range",        "UnavailCond" } },
    { SimulatorError::UnknownFunction,  
            { "AP function not available",  "UnavailCond" } },
};
