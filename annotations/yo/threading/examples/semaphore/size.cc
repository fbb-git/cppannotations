#include "semaphore.ih"

size_t  Semaphore::size() const
{
    lock_guard<mutex> lk(d_mutex);    // get the lock
    return d_nAvailable;
}
