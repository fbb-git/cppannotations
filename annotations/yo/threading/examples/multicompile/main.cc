#include "main.ih"

//code
int main(int argc, char **argv)
{
    workforce();                    // start the worker threads
    thread(jobs).detach();          // start working on the jobs
    results();                      // handle the results.
}
//=
    

