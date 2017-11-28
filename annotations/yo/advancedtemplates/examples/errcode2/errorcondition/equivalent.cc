#include "errorcondition.ih"

    // ec is a concrete error_code. The error-code contains an error-category
    // and the `equivalent' function of that error condition receives the
    // error code and the condition number to verify that the error condition 
    // associated with the error_code matches the condition number.


bool ErrorCondition::equivalent(std::error_code const &ec, int condNr ) 
        const noexcept
{
                                            // call the error category's
                                            //function.
    return (*d_category.find(&ec.category())->second)(condNr, ec);
}
