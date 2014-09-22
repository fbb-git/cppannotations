#include "main.ih"

int main(int argc, char **argv)
try
{
    if (not arguments(argc, argv))
        return 0;

    argv += optind;
    argc -= optind;

    Scanner scanner;

    if (argv[0][0] == '-')
        scanner.lex();

    if (not process(argv, scanner))
        return 1;
}
catch (...)
{
    return 1;
}
