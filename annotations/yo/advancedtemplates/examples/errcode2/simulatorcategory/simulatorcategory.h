#ifndef INCLUDED_SIMULATORCATEGORYS_
#define INCLUDED_SIMULATORCATEGORY_

#include "../categorybase/categorybase.h"

enum class SimulatorError;

class SimulatorCategory: public CategoryBase<SimulatorError>
{
    static SimulatorCategory *s_instance;

    public:
        static SimulatorCategory &instance();

        char const *name() const noexcept override;
        std::string message(int ce) const override;

    private:
        SimulatorCategory() = default;
};

std::error_code make_error_code(SimulatorError ce);
    
#endif







