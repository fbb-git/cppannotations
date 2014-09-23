#include "main.ih"

bool process(char **argv, Tabber &tabber)
{
    char tempfile[] = "tab.tmp";
    
    for (; *argv; ++argv)
    {
        if (not normalFile(*argv))
            continue;
    
        if (!g_quiet)
            cout << "processing `" << *argv << "'\n";

        unlink(tempfile);

        if (rename(*argv, tempfile))
        {
            cout << "can't rename `" << *argv << "'\n";
            return false;
        }

        tabber.run(tempfile, *argv);
    }

    unlink(tempfile);
    return true;
}
