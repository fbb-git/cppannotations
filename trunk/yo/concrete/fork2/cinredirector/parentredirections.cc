#include "cinredirector.ih"

void CinRedirector::parentRedirections()
{
    close(d_cinPipe.readFd());
}
