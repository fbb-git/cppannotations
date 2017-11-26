#ifndef INCLUDED_SIMULATORCATEGORYS_
#define INCLUDED_SIMULATORCATEGORY_

#include <system_error>

#include "../categorydata/categorydata.h"

enum class SimulatorError;

class SimulatorCategory: public std::error_category, public CategoryData
{
    public:
        SimulatorCategory();

        char const *id() const;

        static bool equivalent(char const *conditionName, 
                               std::error_code const &ec);

    private:
        char const *name() const noexcept override;
        std::string message(int ce) const override;
};

inline char const *SimulatorCategory::id() const
{
    return CategoryData::id;
}

// static       // all errors here are Simulator errors
inline bool SimulatorCategory::equivalent(char const *conditionName, 
                                          std::error_code const &ec)
{
    return true;
}

extern SimulatorCategory const g_simulatorCategory;
// extern char const *g_SimError;

std::error_code make_error_code(SimulatorError ce);

    
#endif







