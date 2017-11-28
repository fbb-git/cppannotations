#include "calculatorcategory.ih"

// static
bool CalculatorCategory::equivalent(size_t condNr,
                                    std::error_code const &ec)
{
                            // find the info about the error_code
    auto iter = s_errors.find(static_cast<CalculatorError>(ec.value()));

                            // return true if the conditions match
    return  iter != s_errors.end() 
            and
            std::get<1>(iter->second) == ErrorCondition::instance()[condNr];
}

