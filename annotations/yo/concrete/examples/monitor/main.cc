    #include "monitor.h"

//MAIN
    int main()
    try
    {
        Monitor{}.run();
    }
    catch (int exitValue)
    {
        return exitValue;
    }
//=

    /*
        Example of a session:

        # a.out
        ? start
        Child 1 started
        ? 1 hello world
        ? 3394: Child 1:1:  hello world
        ? 1 hi there!
        ? 3394: Child 1:2:  hi there!
        ? start
        Child 2 started
        ? 3394: Child 1: standing by
        ? 3395: Child 2: standing by
        ? 3394: Child 1: standing by
        ? 3395: Child 2: standing by
        ? stop 1
        ? 3395: Child 2: standing by
        ? 2 hello world
        ? 3395: Child 2:1:  hello world
        ? 1 hello world
        No child number 1
        ? exit3395: Child 2: standing by
        ?
        #
    */
