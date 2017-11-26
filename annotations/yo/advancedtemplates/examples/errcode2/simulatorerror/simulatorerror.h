#ifndef INCLUDED_SIMULATORERRORS_
#define INCLUDED_SIMULATORERROR_

#include <system_error>

//=simerrc
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

// class SimulatorCategory: public std::error_category
// {
//     public:
//         SimulatorCategory();
// 
//     private:
//         char const *name() const noexcept override;
//         std::string message(int ce) const override;
// };

namespace std
{
    template <>
    struct is_error_code_enum<SimulatorError>: public true_type 
    {};
}

// std::error_code make_error_code(SimulatorError ce);
// 
// extern SimulatorCategory const g_simulatorCategory;
// extern char const *g_SimError;
// 
// inline  // all errors here are Simulator errors
// bool simErrorEquivalent(char const *conditionName, std::error_code const &ec)
// {
//     return true;
// }
    
#endif







