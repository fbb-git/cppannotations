#ifndef INCLUDED_SIMULATORCATEGORYS_
#define INCLUDED_SIMULATORCATEGORY_

#include <system_error>
#include "../catmap/catmap.h"

enum class SimulatorError;

class SimulatorCategory: public std::error_category
{
    static SimulatorCategory *s_instance;

    static CatMap<SimulatorError> s_errors;

    public:
        static SimulatorCategory &instance();

        char const *name() const noexcept override;
        std::string message(int ce) const override;
        bool equivalent(std::error_code const &ec, int condNr) const noexcept 
                                                                    override;
    private:
        SimulatorCategory() = default;
};

std::error_code make_error_code(SimulatorError ce);
    
#endif







