#include "errorsource.ih"

std::error_condition make_error_condition(ErrorSource ec)
{
  return {static_cast<int>(ec), errorCategory};
}


