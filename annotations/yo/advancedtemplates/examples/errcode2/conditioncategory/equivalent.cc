#include "conditioncategory.ih"

    // ec is a concrete error_code. The error-code contains an error-category
    // and the `equivalent' function of that error condition receives the
    // error code and the condition number to verify that the error condition 
    // associated with the error_code matches the condition number.


bool ConditionCategory::equivalent(std::error_code const &ec, int condNr ) 
                                                            const noexcept
{
    return ec.category().equivalent(ec, condNr);
}
