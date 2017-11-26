#include "errorsource.ih"

    // condition is the generic error condition: available from s_condition
    // and InputError
    // ec is a concrete error_code. The error-code belongs to an error-enum,
    // and that enum should know whether ec matches that condition
    // e.g., if condition is InputError and ec == MissingParentheses,
    // then the CalculatorError's equivalent returns true. 
    
    // condition is the index in d_info

bool ErrorSource::equivalent(int condition, std::error_code const &ec)
{
    Info const &info = d_info[condition];   // the handling info for this
                                            // condition

    std::cerr << "Calling the function for condition " << condition << 
        ", error code " << ec.value() << 
        ", category " << ec.category().name() << '\n';

    return (*d_category[ec.category().name()])
                (std::get<0>(info), ec);    // pass the cond. name and the ec

//    return true;
//
//    return (*std::get<2>(info))             // call the function
//                (std::get<0>(info), ec);    // pass the cond. name and the ec
}
