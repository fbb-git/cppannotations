#ifndef INCLUDED_CALCULATORCATEGORY_
#define INCLUDED_CALCULATORCATEGORY_

#include "../catmessage/catmessage.h"

enum class CalculatorError;

//impl
class CalculatorCategory: public CatMessage<CalculatorError>
{
    static CalculatorCategory *s_instance;

    public:
        static CalculatorCategory &instance();

        char const *name() const noexcept override;
        std::string message(int ce) const override;
        bool equivalent(std::error_code const &ec, int condNr) const noexcept 
                                                                    override;
    private:
        CalculatorCategory() = default;
};
//=

std::error_code make_error_code(CalculatorError ce);


#endif


