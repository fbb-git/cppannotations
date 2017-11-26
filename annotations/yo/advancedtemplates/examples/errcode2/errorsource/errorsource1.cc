#include "errorsource.ih"

ErrorSource::ErrorSource()
:
    d_info(1)
{
    if (this != &g_errorSource)
        throw std::logic_error("ErrorSource object already defined");
}
