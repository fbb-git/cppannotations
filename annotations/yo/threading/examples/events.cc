// g++ --std=c++0x -pthread events.cc

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <iostream>
#include <chrono>

    class Semaphore
    {
//data
mutable std::mutex d_mutex;
std::condition_variable d_condition;
size_t d_available;
//=
        public:
            Semaphore(size_t available)
            :
                d_available(available)
            {}

            void wait();
            void notify_all();
            size_t size() const;                 // returning d_available
    };

size_t Semaphore::size() const
{
    std::lock_guard<std::mutex> lk(d_mutex);
    return d_available;
}

//notify_all
void Semaphore::notify_all()
{
    std::lock_guard<std::mutex> lk(d_mutex);    // get the lock
    if (d_available++ == 0)
        d_condition.notify_all();   // use notify_one to notify one other
                                    // thread
}   // the lock is released
//=

//wait
void Semaphore::wait()
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

    mutex g_qMutex;
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
            for (size_t run = 0; run != d_trials; ++run)
            {
                ++d_item;
                cout << "Produced item " << d_item << endl;
                g_available.wait();
                {
                    lock_guard<mutex> lg(g_qMutex);
                    g_queue.push(d_item);
                }
                g_filled.notify_all();
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
                g_filled.wait();
                size_t d_item;
                {
                    lock_guard<mutex> lg(g_qMutex);
                    d_item = g_queue.front();
                    this_thread::sleep_for(chrono::milliseconds(10));
                    g_queue.pop();
                }
                g_available.notify_all();
                cout << "\t\tConsumer " << d_nr << " got item " <<
                                                        d_item << endl;
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
        size_t trials = stoul(argv[1]) + 2 / 3 * 3;

        Producer prod(trials); //  << 1);
        Consumer cons1(trials / 3, 1);
        Consumer cons2(trials / 3, 2);
        Consumer cons3(trials / 3, 3);

        thread consume1(cons1);
        thread consume2(cons2);
        thread consume3(cons3);
        thread produce(prod);

        produce.join();
        consume1.join();
        consume2.join();
        consume3.join();
    }


