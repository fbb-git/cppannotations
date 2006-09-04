    #include <iostream>
    #include <streambuf>
    #include <fstream>

    using namespace std;

    int main(int argc, char **argv)
    {
        ofstream errlog;                                // 1
        streambuf *cerr_buffer = 0;                     // 2

        if (argc == 2)
        {
            errlog.open(argv[1]);                       // 3
            cerr_buffer = cerr.rdbuf(errlog.rdbuf());   // 4
        }
        else
        {
            cerr << "Missing log filename\n";
            return 1;
        }

        cerr << "Several messages to stderr, msg 1\n";
        cerr << "Several messages to stderr, msg 2\n";

        cout << "Now inspect the contents of " <<
                argv[1] << "... [Enter] ";
        cin.get();                                      // 5

        cerr << "Several messages to stderr, msg 3\n";

        cerr.rdbuf(cerr_buffer);                        // 6
        cerr << "Done\n";                               // 7
    }
    /*
        Generated output on file argv[1]

        at cin.get():

    Several messages to stderr, msg 1
    Several messages to stderr, msg 2

        at the end of the program:

    Several messages to stderr, msg 1
    Several messages to stderr, msg 2
    Several messages to stderr, msg 3
    */
