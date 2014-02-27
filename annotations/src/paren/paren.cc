//                              paren.cc

#include <fstream>
#include <stack>
#include <string>
#include <iostream>

#include <bobcat/arg>

using namespace std;
using namespace FBB;

bool hdr = false;
bool verbose;

string version("2.00");
string years("1999-2006");

void header(char const *fn)
{
    if (hdr)
        return;

    hdr = true;
    if (verbose)
        cout << "PROCESSING " << fn << endl;
}

void usage(string  const  &prog)
{
    cout << "\n" <<
            prog << " by Frank B. Brokken (f.b.brokken@rug.nl)\n"
            "Copyright " << years << " (c) GPL, V " << version << ".\n"
            "\n"
            "Usage: " << prog << " [-v] file(s)\n"
            "Where:\n"
            "   -h:     print this help-info\n"
            "   -q:     quiet: less output than otherwise\n"
            "   -v:     show the version\n"
            "   file(s): file(s) to check for unbalanced parentheses.\n"
            "            (A simple algorithm is used, in which all \n"
            "            characters are treated equal).\n"
            "\n";
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hqv", argc, argv);

    arg.versionHelp(usage, version.c_str(), 1);

    verbose = !arg.option('q');

    bool ok = true;

    for (size_t idx = arg.nArgs(); idx--; )
    {
        ifstream in(arg[idx]);

        if (!in)
        {
            cout << "Can't read " << arg[idx] << endl;
            ok = false;
            continue;
        }

        hdr = false;

        stack<size_t> linenr;
        unsigned line = 0;
        string text;

        while (getline(in, text))
        {
            ++line;

            for
            (
                string::iterator pos = text.begin(); pos != text.end();
                ++pos
            )
            {
                switch (*pos)
                {
                    case '(':
                        linenr.push(line);
                    break;
                    case ')':
                        if (linenr.empty())
                        {
                            header(argv[idx]);
                            cout << "\tExtra closepar in line " << line
                                 << endl;
                            ok = false;
                            break;
                        }
                        linenr.pop();
                    break;
                }
            }
        }
        while (!linenr.empty())
        {
            header(argv[idx]);
            cout << "\tUnbalanced openpar in line " << linenr.top() << endl;
            linenr.pop();
            ok = false;
        }
    }
    return ok ? 0 : 1;
}
catch(exception const &e)
{
    cout << e.what() << endl;
    return 1;
}
catch(...)
{
    return 1;
}
