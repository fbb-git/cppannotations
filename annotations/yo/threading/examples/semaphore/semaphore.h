#ifndef INCLUDED_SEMAPHORE_
#define INCLUDED_SEMAPHORE_

#include <mutex>
#include <condition_variable>

class Semaphore
{
    std::mutex d_mutex;
    std::condition_variable d_condition;
    size_t d_nAvailable;

    public:
        Semaphore(size_t nAvailable);

        void reduce();      // reduce # available
        void increase();    // increase # available, notify if initially 0
};

#endif
