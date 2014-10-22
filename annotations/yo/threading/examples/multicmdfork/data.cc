#include "main.ih"

mutex g_coutMutex;
mutex g_qsMutex;
queue<string> g_qs;

Semaphore g_workforce(4);
Semaphore g_worker(0);
