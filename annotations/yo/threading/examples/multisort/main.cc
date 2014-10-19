#include "main.ih"

int main()
try
{
    workForce();                    // start the worker threads

    readData();
                                    
    g_taskQ.push(                   // prepare the main task
                Pair(g_data.begin(), g_data.end())
            ); 

    scheduler();

    display();
}
catch (exception const &exc)
{
    cerr << "Exception: " << exc.what() << '\n';
}
