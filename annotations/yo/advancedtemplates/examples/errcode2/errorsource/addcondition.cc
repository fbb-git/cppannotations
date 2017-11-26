#include "errorsource.ih"

void ErrorSource::addCondition(char const *name, char const *description)
{
    addCondition(name);
    d_info.push_back( {name, description } );
}
