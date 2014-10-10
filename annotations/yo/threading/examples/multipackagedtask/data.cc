#include "main.ih"

TaskQueue g_taskQ;

mutex g_resultQMutex;
queue<shared_future<string>> g_resultQ;
condition_variable g_resultCond;

GuardBool g_done;

Semaphore g_workforce(4);
Semaphore g_worker(0);

