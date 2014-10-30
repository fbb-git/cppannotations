#ifndef INCLUDED_CONDITION_H_
#define INCLUDED_CONDITION_H_

class Condition
{
    std::condition_variable d_condition;
    Mutex d_mutex;

    public:
        template <typename Predicate, typename ...Args>
        void wait(Predicate predicate, Args &&...Args)
        {
            std::unique_lock<std::mutex> lk(d_mutex);
            while (not predicate(std::forward<Args>(args)...))
                d_condition.wait(lk);
        }

        void notify_one()
        {
            lock_guard<mutex> lk(d_mutex);
            d_condition.notify_one();
        }

        void notify_all()
        {
            lock_guard<mutex> lk(d_mutex);
            d_condition.notify_all();
        }
};

/*
    Example:

    Condition condition;

    condition.wait(
        [&](any args)
        {
           return return-true-when-waiting-should-stop(any args)
        },
        any args here
    );
*/

#endif
