#include "main.ih"

void workForce()
{
    for (size_t idx = 0; idx != g_sizeofWorkforce; ++idx)
        thread(worker).detach();
}
