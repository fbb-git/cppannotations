#include "main.ih"

void workForce()
{
    for (size_t idx = 0; idx != 4; ++idx)
        thread(worker, idx + 1).detach();
}
