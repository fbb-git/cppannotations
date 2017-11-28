#include "errorcategory.ih"

ErrorCategory::ErrorCategory()
{
    if (this != &g_errorCategory)
        throw std::logic_error("ErrorCategory object already defined");
    
}
