#include "main.ih"

//code
int main()
{
    workforce();                    // start the worker threads
    thread(jobs).detach();          // start working on the jobs
    results();                      // handle the results.
}
//=
