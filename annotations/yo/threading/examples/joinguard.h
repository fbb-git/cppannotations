#include <thread>

class JoinGuard
{
    std::thread d_thread;

    public:
        JoinGuard(std::thread &&threadObj)
        :
            d_thread(std::move(threadObj))
        {}
        ~JoinGuard()
        {
            if (d_thread.joinable())
                d_thread.join();
        }
};
