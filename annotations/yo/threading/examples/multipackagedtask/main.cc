#include "main.ih"

int main(int argc, char **argv)
try
{
    workForce();                    // start the worker threads

    thread(jobs).detach();          // start working on the jobs

    results();                      // handle the results.
}
catch (exception const &exc)
{
    cerr << "Exception: " << exc.what() << '\n';
}
    

