#include "main.ih"

Guard g_taskGuard;

mutex g_taskQMutex;
queue<Task> g_taskQ;

mutex g_resultQMutex;
queue<shared_future<string>> g_resultQ;
condition_variable g_resultCond;

mutex g_doneMutex;
bool g_done = false;

mutex g_qpMutex;
queue<PackagedTask> g_qp;

Semaphore g_workforce(4);
Semaphore g_worker(0);

