#ifndef INCLUDED_SEMAPHORE_
#define INCLUDED_SEMAPHORE_

#include <mutex>
#include <condition_variable>

class Semaphore
{
    mutable std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;

    public:
        Semaphore(size_t nAvailable);

        void wait();      // wait # available
        void notify_all();    // notify_all # available, notify if initially 0

        size_t size() const;
};

#endif
