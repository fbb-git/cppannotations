#ifndef INCLUDED_SIMULATORCATEGORYS_
#define INCLUDED_SIMULATORCATEGORY_

#include <system_error>

enum class SimulatorError;

class SimulatorCategory: public std::error_category
{
    public:
        SimulatorCategory();

    private:
        char const *name() const noexcept override;
        std::string message(int ce) const override;
};

std::error_code make_error_code(SimulatorError ce);

extern SimulatorCategory const g_simulatorCategory;
extern char const *g_SimError;

inline  // all errors here are Simulator errors
bool simErrorEquivalent(char const *conditionName, std::error_code const &ec)
{
    return true;
}

    
#endif







