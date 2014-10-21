#include "main.ih"

void workforce()
{
    for (size_t idx = 0; idx != g_sizeofWorkforce; ++idx)
        thread(worker, idx + 1).detach();
}
