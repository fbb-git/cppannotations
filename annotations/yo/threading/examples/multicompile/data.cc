#include "main.ih"

TaskQueue g_taskQ;

mutex g_resultQMutex;
queue<shared_future<Result>> g_resultQ;
condition_variable g_resultCond;


mutex g_readyMutex;
atomic_bool g_ready;
condition_variable g_readyCond;

atomic_bool g_done;

size_t g_sizeofWorkforce = 6;

Semaphore g_workforce(g_sizeofWorkforce);
Semaphore g_worker(0);
