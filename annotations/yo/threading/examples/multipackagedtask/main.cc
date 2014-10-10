#include "main.ih"

int main(int argc, char **argv)
try
{
    workForce();                    // start the worker threads

    thread(dispatch).detach();      // start the dispatcher

    results();                      // handle the results.
}
catch (exception const &exc)
{
    cerr << "Exception: " << exc.what() << '\n';
}
    

