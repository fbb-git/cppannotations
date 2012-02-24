#include "lexer.ih"

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cerr << "Filename argument required\n";
        return 1;
    }

    Scanner scanner(argv[1], "-");

    scanner.setDebug(argc > 2);

    return scanner.lex();
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}


