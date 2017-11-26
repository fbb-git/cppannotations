#include "errorcategory.ih"

std::error_condition make_error_condition(ErrorSource::Enum ec)
{
    return {static_cast<int>(ec), errorCategory};
}


