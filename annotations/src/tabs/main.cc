#include "main.ih"

int main(int argc, char **argv)
try
{
    if (not arguments(argc, argv))
        return 0;

    argv += optind;
    argc -= optind;

    Tabber tabber;

    if (argv[0][0] == '-')
        tabber.run();

    if (not process(argv, tabber))
        return 1;
}
catch (...)
{
    return 1;
}
