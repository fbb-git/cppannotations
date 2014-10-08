#include "semaphore.ih"

void Semaphore::reduce()
{
    unique_lock<mutex> lk(d_mutex);   // get the lock
    while (d_nAvailable == 0)
        d_condition.wait(lk);   // internally releases the lock
                                // and waits, on exit
                                // acquires the lock again
    --d_nAvailable;              // dec. semaphore
}

