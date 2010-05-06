    #include <iostream>
    #include <cstdio>
    using namespace std;

    int main()
    {
        cout << "hel" << flush;
        printf("lo wo");
        fflush(stdout);
        cout << "rld" << '\n';
    }
    /*
        Generated output:

        hello world

        Without the flushes:

        helrld
        lo wo
    */
