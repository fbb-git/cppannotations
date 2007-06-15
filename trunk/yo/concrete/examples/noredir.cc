    #include <iostream>
    #include <fstream>
    #include <cstdlib>
    using namespace::std;

    int main()
    {
        ofstream of("outfile");

        cout.rdbuf(of.rdbuf());
        cout << "To the of stream" << endl;
        system("echo hello world");
        cout << "To the of stream" << endl;
    }
    /*
        Generated output: on the file `outfile'

        To the of stream
        To the of stream

        On standard output:

        hello world
    */
