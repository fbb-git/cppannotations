// g++-4.4 --std=c++0x -pthread events.cc

#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <ctime>
#include <iostream>
#include <bobcat/selector>
#include <bobcat/irandstream>
#include <bobcat/a2x>

    class Semaphore
    {
        std::mutex d_mutex;
        std::condition_variable d_condition;
        size_t d_semaphore;

        public:
            Semaphore(size_t semaphore)
            :
                d_semaphore(semaphore)
            {}

            void down()
            {
                std::unique_lock<std::mutex> lk(d_mutex);   // get the lock
                while (d_semaphore == 0)
                    d_condition.wait(lk);   // internally releases the lock
                                            // and waits, on exit
                                            // acquires the lock again
                --d_semaphore;              // dec. semaphore
            }   // releases the lock

            void up()
            {
                std::lock_guard<std::mutex> lk(d_mutex);    // get the lock
                if (d_semaphore++ == 0)
                    d_condition.notify_one();   // notifies one other
                                                // (notify_all is also available)
            }   // releases the lock
    };

    using namespace std;
    using namespace FBB;

    Semaphore     g_available(5);
    Semaphore     g_filled(0);
    Selector      g_selector;
    IRandStream   g_rand(0, 100000, time(0));
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
                size_t msec;
                g_rand >> msec;
                g_selector.setAlarm(0, msec);
                g_selector.wait();

                ++d_item;
                cerr << "P " << d_item << ' ' << msec << '\n';
                g_available.down();
                g_queue.push(d_item);
                g_filled.up();
            }
        }
    };

    struct Consumer
    {
        size_t d_trials;
        Consumer(size_t trials)
        :
            d_trials(trials)
        {}

        void operator()()
        {
            for (size_t run = 0; run < d_trials; ++run)
            {
                g_filled.down();
                size_t d_item = g_queue.front();
                g_queue.pop();
                g_available.up();

                size_t msec;
                g_rand >> msec;
                g_selector.setAlarm(0, msec);
                g_selector.wait();
                cout << "C Retrieved item " << d_item << ' ' << msec << '\n';
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
        size_t trials = A2x(argv[1]);

        Producer prod(trials);
        Consumer cons(trials);

        thread produce(prod);
        thread consume(cons);

        produce.join();
        consume.join();

        return 0;
    }
