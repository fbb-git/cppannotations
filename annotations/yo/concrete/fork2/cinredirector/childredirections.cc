#include "cinredirector.ih"

void CinRedirector::childRedirections()
{
    // redirect STDIN_FILENO to the pipe:

    d_cinPipe.readVia(STDIN_FILENO);
}
