// g++ --std=c++0x -pthread events.cc

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <ctime>
#include <iostream>

    class Semaphore
    {
//data
std::mutex d_mutex;
std::condition_variable d_condition;
size_t d_available;
//=
        public:
            Semaphore(size_t available)
            :
                d_available(available)
            {}

            void reduce();
            void increase();
            size_t size() const;    // returning d_available
    };

size_t Semaphore::size() const
{
    lock_guard<mutex> lk(d_mutex);
    return d_nAvailable;
}

//increase
void Semaphore::increase()
{
    std::lock_guard<std::mutex> lk(d_mutex);    // get the lock
    if (d_available++ == 0)
        d_condition.notify_all();   // use notify_one to notify one other
                                    // thread
}   // the lock is released
//=

//reduce
void Semaphore::reduce()
{
    std::unique_lock<std::mutex> lk(d_mutex);   // get the lock
    while (d_available == 0)
        d_condition.wait(lk);   // internally releases the lock
                                // and waits, on exit
                                // acquires the lock again
    --d_available;              // dec. available
}   // the lock is released
//=


    using namespace std;

    Semaphore     g_available(5);
    Semaphore     g_filled(0);
    queue<size_t> g_queue;

    struct Producer
    {
        size_t d_trials;
        size_t d_item;

        Producer(size_t trials)
        :
            d_trials(trials),
            d_item(0)
        {}

        void operator()()
        {
            for (size_t run = 0; run < d_trials; ++run)
            {
                ++d_item;
                cout << "Produced item " << d_item << '\n';
                g_available.reduce();
                g_queue.push(d_item);
                g_filled.increase();
            }
        }
    };

    struct Consumer
    {
        size_t d_trials;
        int d_nr;

        Consumer(size_t trials, int nr)
        :
            d_trials(trials),
            d_nr(nr)
        {}

        void operator()()
        {
            for (size_t run = 0; run != d_trials; ++run)
            {
                g_filled.reduce();
                size_t d_item = g_queue.front();
                g_queue.pop();
                g_available.increase();
                cout << "\t\tConsumer " << d_nr << " got item " <<
                                                        d_item << '\n';
            }
        }
    };


    int main(int argc, char **argv)
    {
        if (argc == 1)
        {
            cerr << "Need nTrials argument\n";
            return 1;
        }
        cerr << "Go!\n";
        size_t trials = stoul(argv[1]);

        Producer prod(trials); //  << 1);
        Consumer cons1(trials, 1);
//        Consumer cons2(trials, 2);

        thread consume1(cons1);
//        thread consume2(cons2);
        thread produce(prod);

        produce.join();
        consume1.join();
//        consume2.join();
    }
