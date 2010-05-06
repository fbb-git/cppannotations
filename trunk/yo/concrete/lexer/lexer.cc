    #include "lexer.h"
    using namespace std;

    int main(int argc, char **argv)
    try
    {
        if (argc == 1)
        {
            cerr << "Filename argument required\n";
            return 1;
        }

        ifstream yyin(argv[1]);
        if (!yyin)
        {
            cerr << "Can't read " << argv[1] << '\n';
            return 1;
        }

        Scanner scanner(&yyin, argv[1]);
        try
        {
            return scanner.yylex();
        }
        catch (Scanner::Error err)
        {
            char const *msg[] =
            {
                "Include specification",
                "Circular Include",
                "Nesting",
                "Read",
            };
            cerr << msg[err] << " error in " << scanner.lastFile() <<
                                ", line " << scanner.lineno() << '\n';
            scanner.stackTrace();
            return 1;
        }
    }
