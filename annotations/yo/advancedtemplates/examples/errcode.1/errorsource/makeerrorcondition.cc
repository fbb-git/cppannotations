#include "errorsource.ih"

std::error_condition make_error_condition(ErrorSource ec)
{
  std::cerr << __FILE__ ": error source = " << (int)ec << '\n';

    return {static_cast<int>(ec), errorCategory};
}


