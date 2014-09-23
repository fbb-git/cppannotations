#include "main.ih"

bool arguments(int argc, char **argv)
{
    if (argc == 1)
    {
        string progname(argv[0]);
        size_t pos = progname.find_last_of('/');
        if (pos != string::npos)
            progname.erase(0, pos + 1);

        usage(progname);
        return false;
    }

    while (true)
    {
        switch (getopt(argc, argv, "c:des:q"))
        {
            case 'e':
                g_entab = true;
            break;

            case 's':
                g_minSpaces = stoul(optarg);
            break;

            case 'c':
                g_tabWidth = stoul(optarg);
            break;

            case 'q':
                g_quiet = true;
            break;

            default:
            return true;
        }
    }
}







