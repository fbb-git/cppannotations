#include "semaphore.ih"

void Semaphore::increase()
{
    lock_guard<mutex> lk(d_mutex);    // get the lock
    if (d_nAvailable++ == 0)
        d_condition.notify_all();   // use notify_one to notify one other
                                    // thread
}
