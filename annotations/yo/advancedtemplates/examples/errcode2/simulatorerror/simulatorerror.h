#ifndef INCLUDED_SIMULATORERRORS_
#define INCLUDED_SIMULATORERROR_

#include <system_error>

//enum
enum class SimulatorError
{
    // no 0
    //  values do not have to be consecutive
    EngineFailure = 1,      // engine malfunction
    ComFailure,             // the radio communication failed
    RangeError,             // outside the range of a navigation system
    UnknownFunction,        // auto pilot function not available
    // ...                  // etc.
};
//=

namespace std
{
    template <>
    struct is_error_code_enum<SimulatorError>: public true_type 
    {};
}

#endif







