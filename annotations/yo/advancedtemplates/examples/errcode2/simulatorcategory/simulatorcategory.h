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
        static bool equivalent(size_t condNr, std::error_code const &ec);
        static SimulatorCategory &instance();

        char const *name() const noexcept override;
        std::string message(int ce) const override;

    private:
        SimulatorCategory();
};

std::error_code make_error_code(SimulatorError ce);
    
#endif







