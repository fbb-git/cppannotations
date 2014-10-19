#include "main.ih"

vector<int> g_data;

TaskQueue g_workQ;

TaskQueue g_taskQ;
mutex g_taskMutex;
condition_variable g_taskCondition;

size_t g_sizeofWorkforce = 8;

Semaphore g_workforce(g_sizeofWorkforce);
Semaphore g_worker(0);

mutex g_cerrMutex;

